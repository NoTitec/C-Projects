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
		
		double count=0;//int 2/5=0�� double2/5�� 0.4
		for (int k = 0; k < n; k++) {
			if (studentsScore[k] > avg) {
				count++;
			}
		}
		//��ճѴ��ο� ����� ���
		cout << fixed;
		cout.precision(3);
		cout << (count / n) * 100<<"%\n";
	}
}