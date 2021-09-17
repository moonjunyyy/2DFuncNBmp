#include <iostream>
#include <cmath>
using namespace std;

#include "bmpNew.h"

int main(int argc, char* argv[])
{
	int width = 256, height = 256;
	unsigned char* blendAvg, * blendGeo;
	
	blendAvg = new unsigned char[width * height * 3];
	blendGeo = new unsigned char[width * height * 3];
	
	for (int y = 0; y < width; y++)
	{
		for (int x = 0; x < width; x++) {
			blendAvg[(y * width + x) * 3 + 0] = (x + y) / 2;
			blendAvg[(y * width + x) * 3 + 1] = (x + y) / 2;
			blendAvg[(y * width + x) * 3 + 2] = (x + y) / 2;

			blendGeo[(y * width + x) * 3 + 0] = sqrt(0.5 * pow(x, 2.) + 0.5 * pow(y, 2.));
			blendGeo[(y * width + x) * 3 + 1] = sqrt(0.5 * pow(x, 2.) + 0.5 * pow(y, 2.));
			blendGeo[(y * width + x) * 3 + 2] = sqrt(0.5 * pow(x, 2.) + 0.5 * pow(y, 2.));
		}
	}

	char NameofFile[50] = "blendavg.bmp";
	WriteBmp(NameofFile, blendAvg, width, height);
	strcpy_s(NameofFile, "blendgeo.bmp");
	WriteBmp(NameofFile, blendGeo, width, height);
	
	delete[] blendAvg;
	delete[] blendGeo;
	return 0;
}