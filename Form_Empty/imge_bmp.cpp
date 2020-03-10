//#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "imge_bmp.h"
#include <math.h>


#define PI 3.14159265358979323846
#define sind(x) (sin(x * PI / 180))
#define cosd(x) (cos(x * PI / 180))

using namespace std;

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile)
{
	// declare bitmap structures
	BITMAPFILEHEADER bmpheader;
	BITMAPINFOHEADER bmpinfo;
	// value to be used in ReadFile funcs
	DWORD bytesread;
	// open file to read from
	HANDLE file = CreateFile(bmpfile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (NULL == file)
		return NULL; // coudn't open file

	// read file header
	if (ReadFile(file, &bmpheader, sizeof (BITMAPFILEHEADER), &bytesread, NULL) == false)  {
		       CloseHandle(file);
		       return NULL;
	      }
	//read bitmap info
	if (ReadFile(file, &bmpinfo, sizeof (BITMAPINFOHEADER), &bytesread, NULL) == false) {
		        CloseHandle(file);
		        return NULL;
	      }
	// check if file is actually a bmp
	if (bmpheader.bfType != 'MB')  	{
		       CloseHandle(file);
		       return NULL;
	      }
	// get image measurements
	width = bmpinfo.biWidth;
	height = abs(bmpinfo.biHeight);

	// check if bmp is uncompressed
	if (bmpinfo.biCompression != BI_RGB)  {
		      CloseHandle(file);
		      return NULL;
	      }
	// check if we have 24 bit bmp
	if (bmpinfo.biBitCount != 24) {
		      CloseHandle(file);
		      return NULL;
	     }

	// create buffer to hold the data
	size = bmpheader.bfSize - bmpheader.bfOffBits;
	BYTE* Buffer = new BYTE[size];

	// move file pointer to start of bitmap data
	SetFilePointer(file, bmpheader.bfOffBits, NULL, FILE_BEGIN);

	// read bmp data
	if (ReadFile(file, Buffer, size, &bytesread, NULL) == false)  {
		     delete[] Buffer;
		     CloseHandle(file);
		     return NULL;
	      }
	// everything successful here: close file and return buffer
	CloseHandle(file);

	return Buffer;
}//LOADPMB

bool SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile)
{
	// declare bmp structures 
	BITMAPFILEHEADER bmfh;
	BITMAPINFOHEADER info;

	// andinitialize them to zero
	memset(&bmfh, 0, sizeof (BITMAPFILEHEADER));
	memset(&info, 0, sizeof (BITMAPINFOHEADER));

	// fill the fileheader with data
	bmfh.bfType = 0x4d42;       // 0x4d42 = 'BM'
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfSize = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+paddedsize;
	bmfh.bfOffBits = 0x36;		// number of bytes to start of bitmap bits

	// fill the infoheader

	info.biSize = sizeof(BITMAPINFOHEADER);
	info.biWidth = width;
	info.biHeight = height;
	info.biPlanes = 1;			// we only have one bitplane
	info.biBitCount = 24;		// RGB mode is 24 bits
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;		// can be 0 for 24 bit images
	info.biXPelsPerMeter = 0x0ec4;     // paint and PSP use this values
	info.biYPelsPerMeter = 0x0ec4;
	info.biClrUsed = 0;			// we are in RGB mode and have no palette
	info.biClrImportant = 0;    // all colors are important

	// now we open the file to write to
	HANDLE file = CreateFile(bmpfile, GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file == NULL)  	{
		    CloseHandle(file);
		    return false;
	   }
	// write file header
	unsigned long bwritten;
	if (WriteFile(file, &bmfh, sizeof (BITMAPFILEHEADER), &bwritten, NULL) == false)  {
		       CloseHandle(file);
		       return false;
	      }
	// write infoheader
	if (WriteFile(file, &info, sizeof (BITMAPINFOHEADER), &bwritten, NULL) == false)  {
		     CloseHandle(file);
		     return false;
	      }
	// write image data
	if (WriteFile(file, Buffer, paddedsize, &bwritten, NULL) == false)  {
		      CloseHandle(file);
		      return false;
	     }

	// and close file
	CloseHandle(file);

	return true;
} // SaveBMP

BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// find the number of padding bytes

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;

	// create new buffer
	BYTE* newbuf = new BYTE[width*height];
	
	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
	for (int column = 0; column < width; column++)  {
		      newpos = row * width + column;
		      bufpos = (height - row - 1) * psw + column * 3;
			  newbuf[newpos] = Buffer[bufpos];
		      newbuf[newpos] = BYTE(0.11*Buffer[bufpos + 2] + 0.59*Buffer[bufpos + 1] + 0.3*Buffer[bufpos]);
	      }

	return newbuf;
}//ConvetBMPToIntensity

BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize)
{
	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return NULL;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	

	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;
	// get the padded scanline width
	int psw = scanlinebytes + padding;
	// we can already store the size of the new padded buffer
	*newsize = height * psw;

	// and create new buffer
	BYTE* newbuf = new BYTE[*newsize];

	// fill the buffer with zero bytes then we dont have to add
	// extra padding zero bytes later on
	memset(newbuf, 0, *newsize);
	

	// now we loop trough all bytes of the original buffer, 
	// swap the R and B bytes and the scanlines
	long bufpos = 0;
	long newpos = 0;
	for (int row = 0; row < height; row++)
	for (int column = 0; column < width; column++)  	{
		bufpos = row * width + column;     // position in original buffer
		newpos = (height - row - 1) * psw + column * 3;           // position in padded buffer
		newbuf[newpos] = Buffer[bufpos];       //  blue
		newbuf[newpos + 1] = Buffer[bufpos];   //  green
		newbuf[newpos + 2] = Buffer[bufpos];   //  red
	}

	return newbuf;
} //ConvertIntensityToBMP

double* Histogram(BYTE* Buffer, int width, int height, double* histogram)
{
	resetHistoram(histogram);
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			histogram[Buffer[row * width + col]]++;

	return histogram;
}

double* resetHistoram(double* histogram)
{
	for (int i = 0; i < 256; i++)
		histogram[i] = 0;
	return histogram;
}

double CalculateMean(double* histogram)
{
	double sum1 = 0, sum2 = 0;
	for (int i = 0; i < 256; i++)
	{
		sum1 += histogram[i] * i;
		sum2 += histogram[i];
	}

	double mean = sum1 / sum2;
	return mean;
}

double CalculateWeight(double* histogram, int width, int height)
{
	double sum1 = 0;
	for (int i = 0; i < 256; i++)
		sum1 += histogram[i];
	
	double weight = sum1 / (width * height);

	return weight;
}

double CalculateVariance(double mean, double* histogram)
{
	double sum1 = 0, sum2 = 0;

	for (int i = 0; i < 256; i++)
	{
		sum1 += ((i - mean) * (i - mean)) * histogram[i];
		sum2 += histogram[i];
	}

	double variance = sum1 / sum2;
	
	return variance;
}

double* thresholding(double threshold, double* histogram)
{
	for (int i = 0; i < 256; i++)
		histogram[i] = histogram[i] < threshold ? 255 : 0;

	return histogram;
}


void DrawCircle(BYTE* Buffer, int width, int height) {

	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return ;

	// now we have to find with how many bytes
	// we have to pad for the next DWORD boundary	
	int padding = 0;
	int scanlinebytes = width * 3;
	while ((scanlinebytes + padding) % 4 != 0)     // DWORD = 4 bytes
		padding++;

	// get the padded scanline width
	int psw = scanlinebytes + padding;
	

	int row = 100;
	int column = 600;
	double angle = 1.0;
	//double radian = angle * (PI / 180.0);
	int radius = 50;
	int numberOfDot = (360 / angle);
	double* newLocation;
	long newpos = 0;
	int index = 0;

	newLocation = CirclePoint(row, column, angle, radius);
	//newLocation = EllipsePoint(row, column, angle, radius);


	while (numberOfDot)
	{
		row = newLocation[index];
		column = newLocation[index + 1];

		newpos = (height - row - 1) * psw + column * 3;

		Buffer[newpos] = 0;   //  blue
		Buffer[newpos + 1] = 0;//  green
		Buffer[newpos + 2] = 0; //  red

		index += 2;
		numberOfDot--;
	}
}//DrawCircle


double* CirclePoint(int row, int column, double angle, int radius)
{
	int index = 0;
	double row1, column1;
	double* imageLocations = new double[(360 / angle) * 2];

	for (double Q = 0; Q < 360 / angle; Q += angle) {
		cout << "Q : " << Q;

		row1 = row + radius * sind(Q);
		imageLocations[index] = row1;
		cout << "\tX : " << imageLocations[index]; index++;

		column1 = column + radius * cosd(Q);
		imageLocations[index] = column1;
		cout << "\tY : " << imageLocations[index] << endl; index++;
	}

	return imageLocations;

}//CirclePoint



double* EllipsePoint(int row, int column, double angle, int radius)
{
	int index = 0;
	double row1, column1;
	double* imageLocations = new double[(360 / angle) * 2];

	for (double Q = 0; Q < 360 / angle; Q += angle) {
		cout << "Q : " << Q;

		row1 = row + 2 * radius * sind(Q);
		imageLocations[index] = row1;
		cout << "\tX : " << imageLocations[index]; index++;

		column1 = column + radius * cosd(Q);
		imageLocations[index] = column1;
		cout << "\tY : " << imageLocations[index] << endl; index++;
	}

	return imageLocations;

}//CirclePoint





