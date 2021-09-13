#include <iostream>
#include <fstream>
using namespace std;

//Sprint 2
#include "bmpNew.h"

int main(int argc, char* argv[])
{
	//Sprint 1
	int width = 1000, height = 500;
	unsigned char* extraBmp;

	extraBmp = new unsigned char[width * height * 3];

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			extraBmp[3 * (i * width + j) + 0] = 0;
			extraBmp[3 * (i * width + j) + 1] = 0;
			extraBmp[3 * (i * width + j) + 2] = 0;
		}
	}

	//Sprint 3
	char NameofFile[] = "extrabmp.bmp";
	WriteBmp(NameofFile, extraBmp, width, height);

	return 0;
}