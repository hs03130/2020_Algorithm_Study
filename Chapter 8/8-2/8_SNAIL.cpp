#include<iostream>
#include<math.h>
using namespace std;

int n, m;
double cache[1000][1000];
double snail(int day, int h);

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> n >> m;
		cout.setf(ios::fixed);
		cout.precision(10);
		cout << snail(0, 0) << endl;
	}
}

double snail(int day, int h) {
	//base case
	if (day == m) {
		if (h >= n) return 1;
		else return 0;
	}
	//memoization
	double& ret = cache[day][h];
	if (ret != -1)	return ret;
	ret = 0.25*snail(day + 1, h + 1) + 0.75*snail(day + 1, h + 2);
	return ret;
}