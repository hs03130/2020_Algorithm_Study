#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool mypair(char brakets, char top);

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		stack<char> s;
		string brackets;
		int f = 1;
		cin >> brackets;

		for (int i = 0; i < brackets.size(); i++) {
			if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') {
				s.push(brackets[i]);
			}
			else {
				if (s.empty() == 1) {
					f = 0;
					break;
				}
				if (mypair(brackets[i], s.top()) == true) {
					s.pop();
				}
				else {
					f = 0;
					break;
				}
			}

		}
		if (s.empty() != true) f = 0;
		if (f == 0) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}

bool mypair(char brackets, char top) {
	if (brackets == ')') {
		if (top == '(') return true;
		else return false;
	}
	else if (brackets == '}') {
		if (top == '{') return true;
		else return false;
	}
	else if (brackets == ']') {
		if (top == '[') return true;
		else return false;
	}
	return 0;
}