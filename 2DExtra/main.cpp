#include <iostream>
#include <fstream>
using namespace std;

//Sprint 2
#include "bmpNew.h"

void drawGrid(unsigned char* img1D, int w, int h, unsigned char RGB[3], short gridSize = 50)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			img1D[3 * (i * w + j) + 0] = 255;
			img1D[3 * (i * w + j) + 1] = 255;
			img1D[3 * (i * w + j) + 2] = 255;

			if (j % gridSize == 0)
			{
				img1D[3 * (i * w + j) + 0] = RGB[2];
				img1D[3 * (i * w + j) + 1] = RGB[1];
				img1D[3 * (i * w + j) + 2] = RGB[0];
			}
			if (i % gridSize == 0)
			{
				img1D[3 * (i * w + j) + 0] = RGB[2];
				img1D[3 * (i * w + j) + 1] = RGB[1];
				img1D[3 * (i * w + j) + 2] = RGB[0];
			}
		}
	}
	return;
}

template<typename F>
void drawGraph(F func, unsigned char* img1D, int w, int h, unsigned char RGB[3])
{
	double j_1 = 0;
	for (int i = 0; i < w; i++)
	{
		double calc = func(i);
		int j = (int)calc + 250;

		if (j > 0 && j < h)
		{
			//Make Spot
			img1D[3 * (j * w + i) + 0] = RGB[2];
			img1D[3 * (j * w + i) + 1] = RGB[1];
			img1D[3 * (j * w + i) + 2] = RGB[0];

			//Pass if it is first line
			if (i == 0) { j_1 = j; continue; }

			//Connect Spot with Smoothing
			int diff = j - j_1;
			if (diff < -1)	//Descending
			{
				for (int iter = -1; iter > diff; iter--)
				{
					int sel = j_1 + iter;
					double mixRate = iter / (double)diff;
					unsigned char backgroundRGB[3] = { 
						img1D[3 * (sel * w + i) + 2],
						img1D[3 * (sel * w + i) + 1],
						img1D[3 * (sel * w + i) + 0] };

					img1D[3 * (sel * w + i - 1) + 0] 
						= sqrt(mixRate * pow(backgroundRGB[2], 2.) + (1. - mixRate) * pow(RGB[2], 2.));
					img1D[3 * (sel * w + i - 1) + 1]
						= sqrt(mixRate * pow(backgroundRGB[1], 2.) + (1. - mixRate) * pow(RGB[1], 2.));
					img1D[3 * (sel * w + i - 1) + 2]
						= sqrt(mixRate * pow(backgroundRGB[0], 2.) + (1. - mixRate) * pow(RGB[0], 2.));

					backgroundRGB[0] = img1D[3 * (sel * w + i + 1) + 2];
					backgroundRGB[1] = img1D[3 * (sel * w + i + 1) + 1];
					backgroundRGB[2] = img1D[3 * (sel * w + i + 1) + 0];

					img1D[3 * (sel * w + i) + 0]
						= sqrt((1. - mixRate) * pow(backgroundRGB[2], 2.) + mixRate * pow(RGB[2], 2.));
					img1D[3 * (sel * w + i) + 1]
						= sqrt((1. - mixRate) * pow(backgroundRGB[1], 2.) + mixRate * pow(RGB[1], 2.));
					img1D[3 * (sel * w + i) + 2]
						= sqrt((1. - mixRate) * pow(backgroundRGB[0], 2.) + mixRate * pow(RGB[0], 2.));
				}
			}
			if (diff > 1)	//Ascending
			{
				for (int iter = 1; iter < diff; iter++)
				{
					int sel = j_1 + iter;
					double mixRate = iter / (double)diff;
					unsigned char backgroundRGB[3] = {
						img1D[3 * (sel * w + i) + 0],
						img1D[3 * (sel * w + i) + 1],
						img1D[3 * (sel * w + i) + 2] };

					img1D[3 * (sel * w + i - 1) + 0]
						= sqrt(mixRate * pow(backgroundRGB[2], 2.) + (1. - mixRate) * pow(RGB[2], 2.));
					img1D[3 * (sel * w + i - 1) + 1]
						= sqrt(mixRate * pow(backgroundRGB[1], 2.) + (1. - mixRate) * pow(RGB[1], 2.));
					img1D[3 * (sel * w + i - 1) + 2]
						= sqrt(mixRate * pow(backgroundRGB[0], 2.) + (1. - mixRate) * pow(RGB[0], 2.));

					backgroundRGB[0] = img1D[3 * (sel * w + i + 1) + 2];
					backgroundRGB[1] = img1D[3 * (sel * w + i + 1) + 1];
					backgroundRGB[2] = img1D[3 * (sel * w + i + 1) + 0];

					img1D[3 * (sel * w + i) + 0]
						= sqrt((1. - mixRate) * pow(backgroundRGB[2], 2.) + mixRate * pow(RGB[2], 2.));
					img1D[3 * (sel * w + i) + 1]
						= sqrt((1. - mixRate) * pow(backgroundRGB[1], 2.) + mixRate * pow(RGB[1], 2.));
					img1D[3 * (sel * w + i) + 2]
						= sqrt((1. - mixRate) * pow(backgroundRGB[0], 2.) + mixRate * pow(RGB[0], 2.));
				}
			}
			j_1 = j;
		}
	}
}

int main(int argc, char* argv[])
{
	int width = 1000, height = 500;
	double PI = 3.141592;
	unsigned char* extraBmp;
	unsigned char Color[3] = { 200,200,200 };

	extraBmp = new unsigned char[width * height * 3];

	// Make Grid
	drawGrid(extraBmp, width, height, Color);

	//Draw sin graph
	Color[0] = 0, Color[1] = 0, Color[2] = 0;
	drawGraph([PI, width](int n) -> double {
		return 100. * sin(2. * PI * 10. * n / (double)width);
		},
		extraBmp, width, height, Color);

	Color[0] = 255, Color[1] = 0, Color[2] = 0;
	drawGraph([PI, width](int n) -> double {
		return 200. * sin(2. * PI * 20. * n / (double)width);
		},
		extraBmp, width, height, Color);

	Color[0] = 0, Color[1] = 0, Color[2] = 255;
	drawGraph([PI, width](int n) -> double {
		double num = n / (double)width;
		return sin(2 * PI * (1. * num + ((50. - 1.) * num * num / 1))) * 100. / (1. + num);
		},
		extraBmp, width, height, Color);

	char NameofFile[] = "extrabmp.bmp";
	WriteBmp(NameofFile, extraBmp, width, height);


	delete[] extraBmp;
	return 0;
}