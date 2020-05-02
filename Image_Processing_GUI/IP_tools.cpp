#include "IP_tools.h"
#include <Windows.h>
#include <string.h>

using namespace System::Drawing;

//3 renk için ayrý mý yapýlacak.
double* extractHistogram(BYTE* Buffer, int width, int height)
{
	double* histogram = new double[255]();
	//memset(histogram, 0, sizeof(histogram));

	//resetHistoram(histogram);
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			histogram[Buffer[row * width + col]]++;

	return histogram;
}


double* extractHistogram(Bitmap^ Buffer, int width, int height)
{
	double* histogram = new double[255]();
	//memset(histogram, 0, sizeof(histogram));

	int val;
	//resetHistoram(histogram);
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
		{
			val = (int)Buffer->GetPixel(col, row).R;
			histogram[val]++;
		}

	return histogram;
}

double* extractHistogram(Bitmap^ Buffer, int width, int height, double* histogramPtr)
{
	int val;
	//resetHistoram(histogram);
	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
		{
			val = (int)Buffer->GetPixel(col, row).R;
			histogramPtr[val]++;
		}

	return histogramPtr;
}

double* resetHistoram(double* histogram)
{
	for (int i = 0; i < 256; i++)
		histogram[i] = 0;
	return histogram;
}

Bitmap^ toBinaryImage(Bitmap^ binarySurface, Bitmap^ grayscaleImage, int thresholdValue)
{
	Color c;
	for (int row = 0; row < grayscaleImage->Height ; row++)
		for (int col = 0; col < grayscaleImage->Width; col++)
		{
			if ((int)(grayscaleImage->GetPixel(col, row).R) < thresholdValue)
				c = Color::FromArgb(0, 0, 0);
			else
				c = Color::FromArgb(255, 255, 255);

			binarySurface->SetPixel(col, row, c);
		}
	return binarySurface;
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

Bitmap^ meanFilter(Bitmap^ Image, int templateSize)
{
	Bitmap^ outputImage = gcnew Bitmap(Image->Width, Image->Height);
	int x, y, i, j, totalR, totalG, totalB, avgR, avgG, avgB;

	Color pxl;
	for (int x = (templateSize - 1) / 2; x < Image->Width - (templateSize - 1) / 2; x++) {
		for (int y = (templateSize - 1) / 2; y < Image->Height - (templateSize - 1) / 2; y++) {
			totalR = 0;
			totalG = 0;
			totalB = 0;

			for (int i = -((templateSize - 1) / 2); i <= (templateSize - 1) / 2; i++) {
				for (int j = -((templateSize - 1) / 2); j <= (templateSize - 1) / 2; j++) {
					pxl = Image->GetPixel(x + i, y + j);

					totalR += pxl.R;
					totalG += pxl.G;
					totalB += pxl.B;
				}
			}

			avgR = totalR / (templateSize * templateSize);
			avgG = totalG / (templateSize * templateSize);
			avgB = totalB / (templateSize * templateSize);

			outputImage->SetPixel(x, y, Color::FromArgb(avgR, avgG, avgB));
		}
	}

	return outputImage;
}

double* thresholding(double thresholdValue, double* histogram)
{
	for (int i = 0; i < 256; i++)
		histogram[i] = histogram[i] < thresholdValue ? 255 : 0;

	return histogram;
}



