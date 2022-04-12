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
int main() {
	int H, M;

	//시간입력
	cin >> H >> M;
	if ((H >= 0 && H <= 23) && (M >= 0 && M <= 59)) {
		//입력시간-45분 으로 시간변경
		minustime(&H, &M);
		//변경시간 출력
		cout << H << " " << M;
	}
	
	
}