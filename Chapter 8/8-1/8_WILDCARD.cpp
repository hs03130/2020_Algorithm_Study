#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string W;
int n;
string filename;
int cache[101];

int wildcard(int w, int f) {
	//base case
	if (w == W.size() && f == filename.size()) return 1;
	if (W[w] != '*' && W[w] != '?' && W[w] != filename[f]) return 0;
	// *가 끝에 올 때
	if (W[w] == '*' && w + 1 == W.size()) return 1;

	//범위
	//if (w == W.size() && f < filename.size()) return false;
	//if (w < W.size() && f == filename.size()) return false;

	//같은지 확인
	if (W[w] == '?' || W[w] == filename[f]) ++w, ++f;
	
	// p*p, pp / *bb* , babbbc 
	if (W[w] == '*') {
		int idxw = w + 1;
		while (W[idxw] != '*' || W[idxw] != '\0') idxw++;
		string str = W.substr(w + 1, idxw - 1);
	}
	
}


int main() {
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> W;
		cin >> n;
		string file[50];	//맞는거 저장
		int idx = 0;
		for (int j = 0; j < n; j++) {
			cin >> filename;
			if (wildcard(0, 0) == 1) file[idx++] = filename;
		}
		sort(file, file + idx);
		for (int k = 0; k < idx; k++) {
			cout << file[k] << endl;
		}
	}
	return 0;
}