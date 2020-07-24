#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

string M;
int m;
string F;
int f;
int cnt = 0;

void normalize(vector<int> num) {
	num.push_back(0);
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	if (num.back() == 0) num.pop_back();
}

vector<int> multiply(const vector<int>A, const vector<int>B) {
	vector<int> C(m + f + 1, 0);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < f; j++) {
			C[i + j] += A[i] * B[j];
		}
	}
	normalize(C);
	return C;
}
void addTo(vector<int>A, const vector<int> B, int k) {
	for(int i=A.size)
	A += B * pow(10, k);
}

void subFrom(vector<int>A, const vector<int> B) {

}

vector<int> karatsuba(const vector<int> A, const vector<int> B) {
	if (m == 0 || f == 0) return vector<int>();
	if (m <= 50) return multiply(A, B);
	int half = m / 2;
	vector<int> A0(A.begin(), A.begin() + half);
	vector<int> A1(A.begin() + half, A.end());
	vector<int> B0(B.begin(), B.begin() + min<int>(f, half));
	vector<int> B1(B.begin() + min<int>(f, half), B.end());
	vector<int> z2 = karatsuba(A1, B1);
	vector<int> z0 = karatsuba(A0, B0);
	


	for (int i = 0; i < f + 2; i++) {
		for (int j = 0; j < m; j++) {
			C[i] += A[m - j] * B[i - j];
		}
	}
}

void FANMEETING() {
	vector<int> A(m), B(f);
	for (int i = 0; i < m; i++) A[i] = (M[i] == 'M');
	for (int i = 0; i < f; i++) B[f - i - 1] = (F[i] == 'M');
	vector<int> C = karatsuba(A, B);

}

int main() {
	int Case;
	cin >> Case;
	for (int i = 0; i < Case; i++) {
		cin >> M;
		m = M.size();
		cin >> F;
		f = F.size();
		FANMEETING(0);
		cout << cnt << endl;
	}
	return 0;
}