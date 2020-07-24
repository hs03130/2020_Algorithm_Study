//188ms , 1.1KB
#include<iostream>
#include<algorithm>
using namespace std;

int n; //0..n-1
int height[20000];
int MAX_A;

void FENCE(int left, int right) {
	if (left == right) {
		MAX_A = max(MAX_A, height[left]);
		return;
	}

	if (left + 1 == right) {
		MAX_A = max(MAX_A, height[left]);
		MAX_A = max(MAX_A, height[right]);
		MAX_A = max(MAX_A, min(height[left], height[right]) * 2);
		return;
	}

	int mid = (left + right) / 2; // 6/2 = 3 -> 0,1,2,3/4,5,6
	FENCE(left, mid);
	FENCE(mid + 1, right);

	int i = mid, j = mid + 1, h= min(height[i], height[j]);
	MAX_A = max(MAX_A, h * 2);
	while (i >= left && j <= right) {
		if (j == right || height[i - 1] > height[j + 1]) { i--; }
		else if (i == left || height[i - 1] < height[j + 1]) { j++; }
		else if (i != left && j != right && height[i-1] == height[j+1]) { i--;  j++; }
		h = min(h, min(height[i], height[j]));
		MAX_A = max(MAX_A, h * (j - i + 1));
	}
	return;
}

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		MAX_A = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		FENCE(0, n - 1);
		cout << MAX_A << endl;
	}
	return 0;
}
