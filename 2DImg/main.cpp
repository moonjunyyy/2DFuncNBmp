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
	
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			mybmp[3 * (i * 200 + j) + 0] = 0;
			mybmp[3 * (i * 200 + j) + 1] = 0;
			mybmp[3 * (i * 200 + j) + 2] = i > 255 ? 255 : i;
		}
	}

	//Sprint 3
	char NameofFile[] = "mybmp.bmp";
	WriteBmp(NameofFile, mybmp, 200, 300);

	delete[] mybmp;
}