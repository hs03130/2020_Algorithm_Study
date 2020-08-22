#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

const int MOD = 20090711;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % MOD;
		return ret;
	}
};

void push_maxheap(vector<int>& maxheap, int newValue) {
	maxheap.push_back(newValue);
	int idx = maxheap.size() - 1;
	while (idx > 0 && maxheap[(idx - 1) / 2] < maxheap[idx]) {
		swap(maxheap[idx], maxheap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
void push_minheap(vector<int>& minheap, int newValue) {
	minheap.push_back(newValue);
	int idx = minheap.size() - 1;
	while (idx > 0 && minheap[(idx - 1) / 2] > minheap[idx]) {
		swap(minheap[idx], minheap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

void pop_maxheap(vector<int>& maxheap) {
	maxheap[0] = maxheap.back();
	maxheap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;

		if (left >= maxheap.size()) break;

		int next = here;
		if (maxheap[next] < maxheap[left])
			next = left;
		if (right < maxheap.size() && maxheap[next] < maxheap[right])
			next = right;
		if (next == here) break;
		swap(maxheap[here], maxheap[next]);
		here = next;
	}
}

void pop_minheap(vector<int>& minheap) {
	minheap[0] = minheap.back();
	minheap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;

		if (left >= minheap.size()) break;

		int next = here;
		if (minheap[next] > minheap[left])
			next = left;
		if (right < minheap.size() && minheap[next] > minheap[right])
			next = right;
		if (next == here) break;
		swap(minheap[here], minheap[next]);
		here = next;
	}
}

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; c++) {
		int N, a, b;
		cin >> N >> a >> b;

		vector <int> maxheap;
		vector <int> minheap;
		RNG rng(a, b);

		int ret = 0;
		for (int i = 0; i < N; i++) {
			if (maxheap.size() == minheap.size())
				push_maxheap(maxheap, rng.next());
			else
				push_minheap(minheap, rng.next());
			if (minheap.size() > 0 && maxheap.size() > 0 && minheap[0] < maxheap[0]) {
				int a = maxheap[0], b = minheap[0];
				pop_maxheap(maxheap);
				pop_minheap(minheap);
				push_maxheap(maxheap, b);
				push_minheap(minheap, a);
			}
			ret = (ret + maxheap[0]) % MOD;
		}
		cout << ret << endl;
	}
	return 0;
}

//최종 중간값x 중간값 합
//빈 힙 접근 오류
//테스트 케이스마다 힙 초기화