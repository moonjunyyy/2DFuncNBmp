#include <iostream>
#include <fstream>
using namespace std;

//Sprint 2
#include "bmpNew.h"

int main(int argc, char* argv[])
{
	//Sprint 1
	int width = 200, height = 300;
	unsigned char* mybmp;

	mybmp = new unsigned char[width * height * 3];
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mybmp[3 * (i * width + j) + 0] = 0;
			mybmp[3 * (i * width + j) + 1] = 0;
			mybmp[3 * (i * width + j) + 2] = i > 255 ? 255 : i;
		}
	}

	//Sprint 3
	char NameofFile[] = "mybmp.bmp";
	WriteBmp(NameofFile, mybmp, 200, 300);

	delete[] mybmp;

	//Sprint 4
	unsigned char* bmpB, * bmpRed, * bmpGreen, * bmpBlue, * bmpMono;
	char NameofFile2[] = "sunflower.bmp";
	bmpB = ReadBmp(NameofFile2, &width, &height);
	
	bmpRed = new unsigned char[width * height * 3];
	bmpGreen = new unsigned char[width * height * 3];
	bmpBlue = new unsigned char[width * height * 3];
	bmpMono = new unsigned char[width * height * 3];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			bmpRed	[3 * (i * width + j) + 0] = 0;
			bmpRed	[3 * (i * width + j) + 1] = 0;
			bmpRed	[3 * (i * width + j) + 2] = bmpB[3 * (i * width + j) + 2];

			bmpGreen[3 * (i * width + j) + 0] = 0;
			bmpGreen[3 * (i * width + j) + 1] = bmpB[3 * (i * width + j) + 1];
			bmpGreen[3 * (i * width + j) + 2] = 0;

			bmpBlue	[3 * (i * width + j) + 0]= bmpB[3 * (i * width + j) + 0];
			bmpBlue	[3 * (i * width + j) + 1] = 0;
			bmpBlue	[3 * (i * width + j) + 2] = 0;

			short Bright
				= bmpB[3 * (i * width + j) + 0]
				+ bmpB[3 * (i * width + j) + 1]
				+ bmpB[3 * (i * width + j) + 2];
			Bright = (double)Bright / 3.;

			bmpMono	[3 * (i * width + j) + 0] = Bright;
			bmpMono	[3 * (i * width + j) + 1] = Bright;
			bmpMono	[3 * (i * width + j) + 2] = Bright;
		}
	}

	char NameofFile3[] = "bmpRed.bmp";
	char NameofFile4[] = "bmpGreen.bmp";
	char NameofFile5[] = "bmpBlud.bmp";
	char NameofFile6[] = "bmpMono.bmp";

	WriteBmp(NameofFile3, bmpRed, width, height);
	WriteBmp(NameofFile4, bmpGreen, width, height);
	WriteBmp(NameofFile5, bmpBlue, width, height);
	WriteBmp(NameofFile6, bmpMono, width, height);

	delete[] bmpB;
	delete[] bmpRed, bmpGreen, bmpBlue, bmpMono;

	return 0;
}