#include<iostream>
#include<cstring>
using namespace std;

const int MOD = 1000000007;
int n;
int cache[100];
int tiling2(int i);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		//È¦¼ö
		if (n % 2 == 1) {	
			cout << (tiling2(0) + MOD - tiling2(n / 2 + 1)) % MOD << endl;
		}				
		//Â¦¼ö
		else {
			int ret = tiling2(0);
			ret = (ret + MOD - tiling2(n / 2 + 1)) % MOD;
			ret = (ret + MOD - tiling2(n / 2)) % MOD;
			cout << ret << endl;
		}	
	}
	return 0;
}

int tiling2(int i) {
	//base case
	if (i == n - 1 || i == n) return 1;
	//memoization
	int& ret = cache[i];
	if (ret != -1) return ret;
	ret = (tiling2(i + 1) + tiling2(i + 2)) % MOD;
	return ret;
}

