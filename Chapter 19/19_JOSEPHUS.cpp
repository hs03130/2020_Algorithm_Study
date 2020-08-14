//Å¥»ç¿ë
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> soldier;
int N, K;

int main() {
	int C;
	cin >> C;
	for (int testcase = 0; testcase < C; testcase++) {
		cin >> N >> K;
		for (int n = 0; n < N; n++) {
			soldier.push(n + 1);
		}
		for (int n = 0; n < N - 2; n++) {
			//cout << soldier.front() << ' ';
			soldier.pop(); //suicide		
			for (int k = 0; k < K - 1; k++) {
				soldier.push(soldier.front());
				soldier.pop();
			}
		}
		int f = soldier.front();
		int b = soldier.back();
		cout << min(f, b) << ' ' << max(f, b) << endl;
		soldier.pop();
		soldier.pop();
	}
}