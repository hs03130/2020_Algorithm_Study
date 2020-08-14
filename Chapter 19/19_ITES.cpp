#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}

	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);	//2^32 안나눔
		return ret % 10000 + 1;
	}
};
/*
int simple(const vector<int>& signals, int k) {
	int ret = 0;
	for (int head = 0; head < signals.size(); head++) {
		int sum = 0;
		for (int tail = head; tail < signals.size(); tail++) {
			sum += signals[tail];
			if (sum == k) ret++;
			if (sum >= k) break;
		}
	}
	return ret;
}

int optimized(const vector<int>& signals, int k) {
	int ret = 0, tail = 0, rangeSum = signals[0];
	for (int head = 0; head < signals.size(); head++) {
		while (rangeSum < k && tail + 1 < signals.size()) {
			rangeSum += signals[++tail];
		}

			if (rangeSum == k) ret++;

			rangeSum -= signals[head];
		
	}
	return ret;
}
*/
int countRanges(int k, int n) {
	RNG rng; //신호값을 생성하는 나수 생성기
	queue<int> range;
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangeSum += newSignal;
		range.push(newSignal);

		while (rangeSum > k) {
			rangeSum -= range.front();	//head del
			range.pop();
		}
		
		if (rangeSum == k) ret++;
	}
	return ret;
}

int main() {
	int C;
	int k, n;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> k >> n;
		cout << countRanges(k, n) << endl;
	}
	return 0;
}