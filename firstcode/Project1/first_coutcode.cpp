#include <iostream>
using namespace std;

void readNumbers(int arr[], int maxsize, int endcon, int& readsize);
double getaverage(const int arr[], int arrsize);

int main()
{
	const int max = 10;
	int stdscore[max] = {};
	int stdnum = 0;

	cout << "inscore" << "end is -1";
	readNumbers(stdscore, max, -1, stdnum);
	cout << getaverage(stdscore, stdnum);
}

void readNumbers(int arr[], int maxsize, int endcon, int& readsize) 
{
	for (readsize; readsize < maxsize; readsize++) {
		cin >> arr[readsize];
		if (arr[readsize] == endcon) {
			break;
		}
	}
}

double getaverage(const int arr[], int arrsize) {
	double sum = 0;
	for (int i = 0; i < arrsize; i++) {
		sum += arr[i];
	}
	return sum/arrsize;
}