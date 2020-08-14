//배열사용
#include<iostream>
#include<cstring>
using namespace std;

int N, K;
int soldier[1000];

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		memset(soldier, 0, sizeof(soldier));
		cin >> N;
		cin >> K;
		int idx = 0;
		for (int i = 0; i < N - 2; i++) {
			soldier[idx] = -1;	//suicide
			for (int j = 0; j < K; j++) {
				idx = (idx + 1) % N;
				while (1) {
					if (soldier[idx] == 0) break;
					idx = (idx + 1) % N;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			if (soldier[i] == 0) { cout << i + 1 << ' '; }
		}
		cout << endl;
	}
}