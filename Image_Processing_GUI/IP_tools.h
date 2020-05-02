#include <Windows.h>

using namespace System::Drawing;

double* extractHistogram(BYTE* Buffer, int width, int height);
double* extractHistogram(Bitmap^ Buffer, int width, int height);
double* extractHistogram(Bitmap^ Buffer, int width, int height, double* histogramPtr);

double* thresholding(double threshold, double* histogram);
double* resetHistoram(double* histogram);

Bitmap^ toBinaryImage(Bitmap^ binarySurface, Bitmap^ grayscaleImage, int thresholdValue);


double CalculateMean(double* histogram);
double CalculateWeight(double* histogram, int width, int height);
double CalculateVariance(double mean, double* histogram);

Bitmap^ meanFilter(Bitmap^ Image, int templateSize = 3);


