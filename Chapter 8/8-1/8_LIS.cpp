#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
/*
int n, s[500];
int cache[500];
int lis(int start);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s[j];
		}
		int maxLen = 0;
		for (int start = 0; start < n; start++) {
			maxLen = max(maxLen, lis(start));
		}
		cout << maxLen << endl;
	}
	return 0;
}

int lis(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (s[next] > s[start])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}
*/

int n, s[500];
int cache[501];
int lis(int start);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> s[j];
		}
		cout << lis(-1) - 1 << endl;
	}
}

int lis(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || s[next] > s[start])
			ret = max(ret, lis(next) + 1);
	}
	return ret;
}