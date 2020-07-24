#pragma warning(disable:4996)
#include<stdio.h>
#include<memory.h>

int countPairings (int taken[10], int n, int M[][10]);

int main() {
	//n: 학생수, m: 친구 쌍의 수
	int C, n, m, N = 0;
	int M[10][10] = { 0, }, x, y;
	int taken[10] = { 0, };
	int i, c;
	
	scanf("%d", &C);		//테스트 케이스 수

	for (c = 0; c < C; c++) {
		scanf("%d %d", &n, &m); //학생수, 친구 쌍의 수
		//M 초기화
		memset(M, 0, sizeof(M));
		//친구 쌍 정보 입력
		for (i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			if (x < y) {
				M[x][y] = 1;
			}
			else {
				M[y][x] = 1;
			}
		}
		N = countPairings(taken, n, M);	//경우의 수 구하기
		printf("%d\n", N);
	}
	return 0;
}

int countPairings(int taken[10], int n, int M[][10]) {
	int firstFree = -1;
	int ret = 0;
	int i;
	for (i = 0; i < n; i++) {
		if (taken[i] == 0) {
			firstFree = i;
			break;
		}
	}
	//기저사례 모두 짝을 맺은 경우
	if (firstFree == -1) {
		return 1;
	}
	//짝지을 학생 결정
	for (int pair = firstFree + 1; pair < n; pair++) {
		if (taken[pair] != 1 && M[firstFree][pair] == 1) {
			taken[pair] = 1;
			taken[firstFree] = 1;
			ret += countPairings(taken, n, M);
			//다음 경우 세기 전 초기화?
			taken[pair] = 0;
			taken[firstFree] = 0;		
		}
	}
	return ret;
}