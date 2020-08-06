#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, triangle[100][100];
int cache[100][100];
int trianglepath(int y, int x);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> triangle[j][k];
			}
		}
		cout << trianglepath(0, 0) << endl;
	}
	return 0;
}

int trianglepath(int y, int x) {
	//base case
	if (y == n - 1) return triangle[y][x];
	if (x > y) return 0;
	//memoization
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	ret = max(trianglepath(y + 1, x), trianglepath(y + 1, x + 1)) + triangle[y][x];
	return ret;
}
