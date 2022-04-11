
#include <iostream>
using namespace std;
int main()
{
	int front;
	int last;
	int line;

	cout << "몇단까지 출력할까요";
	cin >> front;
	cout << "몇까지 곱할까요";
	cin >> last;
	cout << "한 줄에 몇단씩 출력할까요";
	cin >> line;
	
	//12단까지 출력 한줄에 line단까지출력
	//line단까지 last곱출력완료후 줄바꿈
	//현재단+line단까지출력 만약 현재단+line 단 합이 12보다작으면 12전단까지 출력
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

