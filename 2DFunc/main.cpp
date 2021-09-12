#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	fstream fio("2Dgraph.txt",ios::out);
	if (fio.fail()) { return 1; }
	double PI = 3.141592;

	for (int j = 0; j < 20; j++)
	{
		fio << ", " << PI / 20 * j;
	}
	fio << endl;
	for (int i = 0; i < 20; i++)
	{
		fio << PI / 20 * i;
		for (int j = 0; j < 20; j++)
		{
			fio << ", " << sin(PI / 20 * i) * sin(PI / 20 * j);
		}
		fio << endl;
	}
	return 0;
}