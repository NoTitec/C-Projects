
#include <iostream>
using namespace std;
int main()
{
	int front;
	int last;
	int line;

	cout << "��ܱ��� ����ұ��";
	cin >> front;
	cout << "����� ���ұ��";
	cin >> last;
	cout << "�� �ٿ� ��ܾ� ����ұ��";
	cin >> line;
	
	//12�ܱ��� ��� ���ٿ� line�ܱ������
	//line�ܱ��� last����¿Ϸ��� �ٹٲ�
	//�����+line�ܱ������ ���� �����+line �� ���� 12���������� 12���ܱ��� ���
	int incresenumber = line;
	int curplin = 0;
	while (curplin<front) {
		if ((curplin + line) > front)
		{
			line = curplin%line;
		}
		for (int i = 1; i <= last; i++) {
			for (int j = 1; j <= line; j++) {
				cout << j << "*" << i << "=" << j * i << "   ";
			}
			cout << '\n';
		}
		cout << '\n';
		curplin += line;
		
	}
}

