#include "DrawShape.h"
#include <windows.h>
#include <math.h>
#include <iostream>


#define PI 3.14159265358979323846
#define sind(x) (sin(x * PI / 180))
#define cosd(x) (cos(x * PI / 180))

using namespace std;


void DrawCircle(BYTE* Buffer, int width, int height) {

	// first make sure the parameters are valid
	if ((NULL == Buffer) || (width == 0) || (height == 0))
		return;

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

		Buffer[newpos] = 0;		//  blue
		Buffer[newpos + 1] = 0;	//  green
		Buffer[newpos + 2] = 0; //  red

		index += 2;
		numberOfDot--;
	}
}//DrawCircle

double* CirclePoint(int row, int column, double angle, int radius)
{
	int index = 0;
	double row1, column1;
	double* imageLocations = new double[(360 / angle) * 2.0];

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
	double* imageLocations = new double[(360 / angle) * 2.0];

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

