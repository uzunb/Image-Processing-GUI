#include "IP_tools.h"
#include <Windows.h>
#include <string.h>
#include <thread>
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

	int val;
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
	for (int i = 0; i < MAX_INTENSITY; i++)
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


double CalculateMean(double* histogram, int start, int finish)
{
	double sum1 = 0, sum2 = 0;
	for (int i = start; i < finish; i++)
	{
		sum1 += histogram[i] * i;
		sum2 += histogram[i];
	}
	return sum1 == sum2 ? 1 : sum1 / sum2;
}

double CalculateWeight(double* histogram, int width, int height, int start, int finish)
{
	double sum1 = 0;
	for (int i = start; i < finish; i++)
		sum1 += histogram[i];

	return sum1 / (width * height);
}

double CalculateVariance(double mean, double* histogram, int start, int finish)
{
	double sum1 = 0, sum2 = 0;
	for (int i = start; i < finish; i++)
	{
		sum1 += ((i - mean) * (i - mean)) * histogram[i];
		sum2 += histogram[i];
	}
	return sum1 == sum2 ? 1 : sum1 / sum2;
}


int automaticThresholdSelection(double randomThreshold, double* histogram)
{
	int leftMean = 0, rightMean = 0, optimalThresholdValue = 0 ;
	while (optimalThresholdValue != randomThreshold)
	{
		optimalThresholdValue = randomThreshold;
		leftMean = CalculateMean(histogram, 0, randomThreshold);
		rightMean = CalculateMean(histogram, randomThreshold, MAX_INTENSITY);
		randomThreshold = (leftMean + rightMean) / 2;
	}
	return optimalThresholdValue;
}




Bitmap^ meanFiltering(Bitmap^ Image, int templateSize)
{
	Bitmap^ outputImage = gcnew Bitmap(Image->Width, Image->Height);
	int totalR, totalG, totalB, avgR, avgG, avgB;

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



Bitmap^ medianFiltering(Bitmap^ Image, int templateSize)
{
	Bitmap^ outputImage = gcnew Bitmap(Image->Width, Image->Height);
	int strElementSize = templateSize * templateSize;
	int *R = new int[strElementSize]();
	int* G = new int[strElementSize]();
	int* B = new int[strElementSize]();

	Color pxl, medianPxl;
	for (int x = (templateSize - 1) / 2; x < Image->Width - (templateSize - 1) / 2; x++) {
		for (int y = (templateSize - 1) / 2; y < Image->Height - (templateSize - 1) / 2; y++) {
			
			int strlElIndex = 0;
			for (int i = -((templateSize - 1) / 2); i <= (templateSize - 1) / 2; i++) {
				for (int j = -((templateSize - 1) / 2); j <= (templateSize - 1) / 2; j++) {
					pxl = Image->GetPixel(x + i, y + j);

					R[strlElIndex] = pxl.R;
					G[strlElIndex] = pxl.G;
					B[strlElIndex] = pxl.B;

					strlElIndex++;
				}
			}

			medianPxl = findMedianPxls(R, G, B, strElementSize);
			outputImage->SetPixel(x, y, medianPxl);
		}
	}

	return outputImage;
}

//Tek fonksiyon yapýlabilir. MultiThreading yapmayý dene.
Color findMedianPxls(int* R, int* G, int* B, int elementSize)
{
	int medianR, medianG, medianB;
	/*std::thread (findMedianR, R, elementSize, std::ref(medianR)).detach();
	std::thread (findMedianG, G, elementSize, std::ref(medianG)).detach();
	std::thread (findMedianB, B, elementSize, std::ref(medianB)).detach();
	printf("Threads was work.\n");*/

	findMedianB(B, elementSize, medianB);
	findMedianG(G, elementSize, medianG);
	findMedianR(R, elementSize, medianR);


	return Color::FromArgb(medianR, medianG, medianB);
}

void findMedianR(int* pxl, const int elementSize, int const& outputValue)
{
	int& y = const_cast<int&>(outputValue);
	int temp = 0;
	for (int i = 0; i < elementSize; i++) {
		for (int j = i + 1; j < elementSize; j++) {
			if (pxl[j] < pxl[i]) {
				temp = pxl[i];
				pxl[i] = pxl[j];
				pxl[j] = temp;
			}
		}
	}
	y = pxl[(elementSize - 1) / 2];
}

void findMedianG(int* pxl, const int elementSize, int const& outputValue)
{
	int& y = const_cast<int&>(outputValue);
	int temp = 0;
	for (int i = 0; i < elementSize; i++) {
		for (int j = i + 1; j < elementSize; j++) {
			if (pxl[j] < pxl[i]) {
				temp = pxl[i];
				pxl[i] = pxl[j];
				pxl[j] = temp;
			}
		}
	}
	y = pxl[(elementSize - 1) / 2];
}

void findMedianB(int* pxl, const int elementSize, int const& outputValue)
{
	int& y = const_cast<int&>(outputValue);
	int temp = 0;
	for (int i = 0; i < elementSize; i++) {
		for (int j = i + 1; j < elementSize; j++) {
			if (pxl[j] < pxl[i]) {
				temp = pxl[i];
				pxl[i] = pxl[j];
				pxl[j] = temp;
			}
		}
	}
	y = pxl[(elementSize - 1) / 2];
}


Bitmap^ gaussianSmoothing(Bitmap^ Image, int templateSize)
{
	Bitmap^ outputImage = gcnew Bitmap(Image->Width, Image->Height);
	int strElementSize = templateSize * templateSize;
	int* gaussianMatrix = getGaussianMatrix(templateSize);
	int gaussianMatrixSum = getGaussianMatrixSum(templateSize);
	int totalR, totalG, totalB, avgR, avgG, avgB, index;


	Color pxl;
	for (int x = (templateSize - 1) / 2; x < Image->Width - (templateSize - 1) / 2; x++) {
		for (int y = (templateSize - 1) / 2; y < Image->Height - (templateSize - 1) / 2; y++) {

			totalR = 0;
			totalG = 0;
			totalB = 0;

			index = 0;
			for (int i = -((templateSize - 1) / 2); i <= (templateSize - 1) / 2; i++) {
				for (int j = -((templateSize - 1) / 2); j <= (templateSize - 1) / 2; j++) {
					pxl = Image->GetPixel(x + i, y + j);
					
					totalR = totalR + pxl.R * gaussianMatrix[index];
					totalG = totalG + pxl.G * gaussianMatrix[index];
					totalB = totalB + pxl.B * gaussianMatrix[index];

					avgR = totalR / gaussianMatrixSum;
					avgG = totalG / gaussianMatrixSum;
					avgB = totalB / gaussianMatrixSum;

					index++;
				}
			}
			outputImage->SetPixel(x, y, Color::FromArgb(avgR, avgG, avgB));
		}
	}
	return outputImage;
}

int* getGaussianMatrix(int templateSize)
{
	static int matrix_7x7[] = { 0,0,1,2,1,0,0,0,3,13,22,13,3,0,1,13,59,97,59,13,1,2,22,97,159,97,22,2,1,13,59,97,59,13,1,0,3,13,22,13,3,0,0,0,1,2,1,0,0 };
	static int matrix_5x5[] = { 1, 4, 7, 4, 1, 4, 16, 26, 16, 4, 7, 26, 41, 26, 7, 4, 16, 26, 16, 4, 1, 4, 7, 4, 1 };
	static int matrix_3x3[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };

	if (templateSize == 5) return matrix_5x5;
	else if (templateSize == 3) return matrix_3x3;
	else if (templateSize == 7) return matrix_7x7;
	else return ERROR;

}

int getGaussianMatrixSum(int templateSize)
{
	int matrixSum_7x7 = 1003;
	int matrixSum_5x5 = 273;
	int matrixSum_3x3 = 16;

	if (templateSize == 5) return matrixSum_5x5;
	else if (templateSize == 3) return matrixSum_3x3;
	else if (templateSize == 7) return matrixSum_7x7;
	else return ERROR;
}


//hýzlandýrabilrisin.
double thresholdSelectionWithOtsu(int threshold, double* histogram, int width, int height)
{
	
	double meanBackground = CalculateMean(histogram, 0, threshold);
	double meanForeground = CalculateMean(histogram, threshold, MAX_INTENSITY);
	
	double weightBackground = CalculateWeight(histogram, width, height, 0, threshold);
	double weightForeground = CalculateWeight(histogram, width, height, threshold, MAX_INTENSITY);

	double varianceBackground = CalculateVariance(meanBackground, histogram, 0, threshold);
	double varianceForeground = CalculateVariance(meanForeground, histogram, threshold, MAX_INTENSITY);

	double betweenClassVariance = varianceBackground * weightBackground + varianceForeground * weightForeground;
	//double withinClassVariance = weightBackground * weightForeground * (meanBackground - meanForeground) * (meanBackground - meanForeground);

	
	return betweenClassVariance;
}


Bitmap^ K_MeansClustring(Bitmap^ grayscaleImage, double *histogram, int width, int height)
{
	Bitmap^ outImage = grayscaleImage;

	int K1_Class[MAX_INTENSITY] = {}, K1 = histogram[85], _K1, K1_index = 0, K1_totalWeight = 0, K1_totalHist = 0; //Black : 0
	int K2_Class[MAX_INTENSITY] = {}, K2 = histogram[170], _K2, K2_index = 0, K2_totalWeight = 0, K2_totalHist = 0; //White : 255

	while ((K1 != _K1) & (K2 != _K2))
	{
		for (int index = 0; index < MAX_INTENSITY; index++)
		{
			if (abs(K1 - histogram[index]) >= abs(K2 - histogram[index]))
			{
				K1_Class[index] = histogram[index];
				K1_totalWeight += histogram[index] * index;
				K1_totalHist += histogram[index];
			}
			else
			{
				K2_Class[index] = histogram[index];
				K2_totalWeight += histogram[index] * index;
				K2_totalHist += histogram[index];
			}
		}
		_K1 = K1_totalWeight / K1_totalHist;
		_K2 = K2_totalWeight / K2_totalHist;

		K1 = _K1;
		K2 = _K2;
	}

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++) {
			Color pxl = outImage->GetPixel(col, row);
			if (abs(K1 - (int)pxl.R) >= abs(K2 - (int)pxl.R))
				outImage->SetPixel(col, row, Color::FromArgb(255, 255, 255));
			else
				outImage->SetPixel(col, row, Color::FromArgb(0, 0, 0));
		}

	return outImage;
}