#include<iostream>
#include<cstring>
using namespace std;

int n;
int cache[100];
int tiling2(int i);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << tiling2(0) << endl;
	}
	return 0;
}

int tiling2(int i) {
	//base case
	if (i == n - 1 || i == n) return 1;
	//memoization
	int& ret = cache[i];
	if (ret != -1) return ret;
	ret = (tiling2(i + 1) + tiling2(i + 2)) % 1000000007;
	return ret;
}
