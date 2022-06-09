#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n=0;
		int sum = 0;
		cin >> n;
		int* studentsScore = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> studentsScore[j];
			sum += studentsScore[j];
		}
		double avg=(double)sum / (double)n;
		
		double count=0;//int 2/5=0임 double2/5는 0.4
		for (int k = 0; k < n; k++) {
			if (studentsScore[k] > avg) {
				count++;
			}
		}
		//평균넘는인원 백분율 출력
		cout << fixed;
		cout.precision(3);
		cout << (count / n) * 100<<"%\n";
	}
}