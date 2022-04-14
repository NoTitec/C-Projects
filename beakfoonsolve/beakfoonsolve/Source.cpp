#include <iostream>
using namespace std;
void minustime(int *H,int *M) {
	int h=*H, m=*M;
	if ((m - 45) < 0) {
		if (h - 1 < 0) {
			*H = 23;
			if ((m - 45) < 0) {
				*M = *M + 60 - 45;
			}
			else{ 
				*M = 59; 
			}
			
		}
		else {
			*H = h - 1;
			if ((m - 45) < 0) {
				*M = *M + 60 - 45;
			}
		}
	}
	else {
		*M= m - 45;
	}
}
void plustime(int* a, int* b, int* c) {

	if ((*b + *c) > 59) {
		
		*a = *a + (*c+*b) / 60;
		*b = (*b + *c) % 60;
		*a %= 24;
	}
	else {
		*b += *c;
	}
}

int main() {
	int a[2];
	for (int i = 0; i <= 1; i++) {
		cin >> a[i];
	}
	int c;
	cin >> c;

	if ((a[0] <= 23 && a[0] >= 0) && (a[1] >= 0 && a[1] <= 59)&&(c>=0&&c<=1000)) {
		plustime(&a[0], &a[1], &c);
	}

	cout << a[0]<<" " << a[1];
}