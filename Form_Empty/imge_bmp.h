#include <windows.h>

//% hem pointer hem ref anlamýnda

BYTE* LoadBMP(int% width, int% height, long% size, LPCTSTR bmpfile);
bool  SaveBMP(BYTE* Buffer, int width, int height, long paddedsize, LPCTSTR bmpfile);
BYTE* ConvertBMPToIntensity(BYTE* Buffer, int width, int height);
BYTE* ConvertIntensityToBMP(BYTE* Buffer, int width, int height, long* newsize);
void DrawCircle(BYTE* Buffer, int width, int height);
double* CirclePoint(int row, int column, double angle, int radius);
double* EllipsePoint(int row, int column, double angle, int radius);

double* Histogram(BYTE* Buffer, int width, int height, double* histogram);

double* resetHistoram(double* histogram);
double CalculateMean(double* histogram);
double CalculateWeight(double* histogram, int width, int height);
double CalculateVariance(double mean, double* histogram);
double* thresholding(double threshold, double* histogram);

