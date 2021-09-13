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
	double j_1;
	for (int i = 0; i < w; i++)
	{
		double calc = func(i);
		int j = (int)calc + 250;

		cout << j << endl;

		img1D[3 * (j * w + i) + 0] = RGB[2];
		img1D[3 * (j * w + i) + 1] = RGB[1];
		img1D[3 * (j * w + i) + 2] = RGB[0];
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

	char NameofFile[] = "extrabmp.bmp";
	WriteBmp(NameofFile, extraBmp, width, height);


	delete[] extraBmp;
	return 0;
}