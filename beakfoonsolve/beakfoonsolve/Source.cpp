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

	//�ð��Է�
	cin >> H >> M;
	if ((H >= 0 && H <= 23) && (M >= 0 && M <= 59)) {
		//�Է½ð�-45�� ���� �ð�����
		minustime(&H, &M);
		//����ð� ���
		cout << H << " " << M;
	}
	
	
}