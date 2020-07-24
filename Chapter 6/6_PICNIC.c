#pragma warning(disable:4996)
#include<stdio.h>
#include<memory.h>

int countPairings (int taken[10], int n, int M[][10]);

int main() {
	//n: �л���, m: ģ�� ���� ��
	int C, n, m, N = 0;
	int M[10][10] = { 0, }, x, y;
	int taken[10] = { 0, };
	int i, c;
	
	scanf("%d", &C);		//�׽�Ʈ ���̽� ��

	for (c = 0; c < C; c++) {
		scanf("%d %d", &n, &m); //�л���, ģ�� ���� ��
		//M �ʱ�ȭ
		memset(M, 0, sizeof(M));
		//ģ�� �� ���� �Է�
		for (i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			if (x < y) {
				M[x][y] = 1;
			}
			else {
				M[y][x] = 1;
			}
		}
		N = countPairings(taken, n, M);	//����� �� ���ϱ�
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
	//������� ��� ¦�� ���� ���
	if (firstFree == -1) {
		return 1;
	}
	//¦���� �л� ����
	for (int pair = firstFree + 1; pair < n; pair++) {
		if (taken[pair] != 1 && M[firstFree][pair] == 1) {
			taken[pair] = 1;
			taken[firstFree] = 1;
			ret += countPairings(taken, n, M);
			//���� ��� ���� �� �ʱ�ȭ?
			taken[pair] = 0;
			taken[firstFree] = 0;		
		}
	}
	return ret;
}