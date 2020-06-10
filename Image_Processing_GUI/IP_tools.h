#include <Windows.h>
#define MAX_INTENSITY 256

using namespace System::Drawing;

double* extractHistogram(BYTE* Buffer, int width, int height);
double* extractHistogram(Bitmap^ Buffer, int width, int height);
double* extractHistogram(Bitmap^ Buffer, int width, int height, double* histogramPtr);

int automaticThresholdSelection(double randomThreshold, double* histogram);
double thresholdSelectionWithOtsu(int threshold, double* histogram, int width, int height);
double* resetHistoram(double* histogram);

Bitmap^ toBinaryImage(Bitmap^ binarySurface, Bitmap^ grayscaleImage, int thresholdValue);
Bitmap^ K_MeansClustering(Bitmap^ grayscaleImage, double* histogram, int width, int height);
Bitmap^ K_MeansClustering(double* histogram, int width, int height, int classNumber);
bool isEqualK(int* k, int* _k, int classNumber);

//double CalculateMean(double* histogram);
double CalculateMean(double* histogram, int start = 0, int finish = MAX_INTENSITY);
double CalculateWeight(double* histogram, int width, int height, int start = 0, int finish = MAX_INTENSITY);
double CalculateVariance(double mean, double* histogram, int start = 0, int finish = MAX_INTENSITY);

Bitmap^ meanFiltering(Bitmap^ Image, int templateSize = 3);
Bitmap^ medianFiltering(Bitmap^ Image, int templateSize = 3);
Bitmap^ gaussianSmoothing(Bitmap^ Image, int templateSize = 3);

Color findMedianPxls(int* R, int* G, int* B, int elementSize);
void findMedianR(int* pxl, const int elementSize, int const& outputValue);
void findMedianG(int* pxl, const int elementSize, int const& outputValue);
void findMedianB(int* pxl, const int elementSize, int const& outputValue);
int* getGaussianMatrix(int templateSize);
int getGaussianMatrixSum(int templateSize);

Bitmap^ connectivityLabeling(Bitmap^ binaryImage, int width, int height);
void update(Bitmap^ labIm, int row, int col, Color B, Color C);
bool isAgainCollision(int arr[], int arrSize, int first, int second);
Bitmap^ dilationBinaryImage(Bitmap^ binaryImage, int width, int height);
Bitmap^ erosionBinaryImage(Bitmap^ binaryImage, int width, int height);


