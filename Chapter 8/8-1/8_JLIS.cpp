#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];
int jlis(int a, int b);

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> B[i];
		}
		cout << jlis(-1, -1) - 2 << endl;
	}
	return 0;
}

int jlis(int idxa, int idxb) {
	int& ret = cache[idxa + 1][idxb + 1];
	if (ret != -1) return ret;

	ret = 2;
	long long a = (idxa == -1 ? NEGINF : A[idxa]);
	long long b = (idxb == -1 ? NEGINF : B[idxb]);
	long long maxelem = max(a, b);

	for (int nextA = idxa + 1; nextA < n; nextA++) {
		if (maxelem < A[nextA])
			ret = max(ret, jlis(nextA, idxb) + 1);
	}
	for (int nextB = idxb + 1; nextB < m; nextB++) {
		if (maxelem < B[nextB])
			ret = max(ret, jlis(idxa, nextB) + 1);
	}
	return ret;
}