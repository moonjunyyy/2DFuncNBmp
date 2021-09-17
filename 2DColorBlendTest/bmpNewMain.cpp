#include <iostream>
//#include "bmpOld.h"
#include "bmpNew.h"  // suh
int main() {
	// interlaced BGR
	unsigned char *data = new unsigned char[15000];
	for (int i = 0; i < 5000; i++) {
		data[i * 3] = 0;       // B
		data[i * 3 + 1] = 0;   // G
		data[i * 3 + 2] = 255; // R
	}

	// make a bmp image
	WriteBmp("suhR.bmp", data, 100, 50);
	// read a bmp image
	int x, y;
	// return raw image pointer
	unsigned char *bmpB = ReadBmp("todaejun.bmp", &x, &y); // 24bits bmp
	std::cout << " Main " << x << " by " << y << std::endl;
	
	return 123;
}
