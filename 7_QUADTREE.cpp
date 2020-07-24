//8ms 750B

#include<iostream>
using namespace std;

string st;
int find_idx(int idx) {
	if (st[idx] == 'x') {
		idx += 1;
		for (int i = 0; i < 4; i++) {
			idx = find_idx(idx);
		}
		return idx;
	}
	return idx + 1;
}
void QUADTREE(int idx) {
	if (st[idx] == '\0') {
		return;
	}
	if (st[idx] == 'x') {
		cout << 'x';
		int idx1, idx2, idx3, idx4;
		idx1 = idx + 1;
		idx2 = find_idx(idx1);
		idx3 = find_idx(idx2);
		idx4 = find_idx(idx3);

		QUADTREE(idx3);
		QUADTREE(idx4);
		QUADTREE(idx1);
		QUADTREE(idx2);
	}
	else {
		cout << st[idx];
	}
	return;
}

int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> st;
		QUADTREE(0);
		cout << endl;
	}
	return 0;
}
