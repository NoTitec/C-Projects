#include <iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string input;
		int nowscore=0;//int 값은 초기화필요
		int resultscore=0;
		char before;
		cin >> input;
		for (char a : input) {
			if (a == 'O') {
				nowscore++;
				resultscore += nowscore;
			}
			else {
				nowscore = 0;
			}
		}
		cout << resultscore << "\n";
	}
}