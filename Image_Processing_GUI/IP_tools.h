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

Bitmap^ meanFiltering(Bitmap^ Image, int templateSize = 3);
Bitmap^ medianFiltering(Bitmap^ Image, int templateSize = 3);
Bitmap^ gaussianSmoothing(Bitmap^ Image, int templateSize = 3);

Color findMedianPxls(int* R, int* G, int* B, int elementSize);
void findMedianR(int* pxl, const int elementSize, int const& outputValue);
void findMedianG(int* pxl, const int elementSize, int const& outputValue);
void findMedianB(int* pxl, const int elementSize, int const& outputValue);
int* getGaussianMatrix(int templateSize);
int getGaussianMatrixSum(int templateSize);


