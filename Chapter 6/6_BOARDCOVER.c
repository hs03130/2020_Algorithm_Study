#pragma warning(disable:4996)
#include<stdio.h>

int H, W, Wnum = 0;
int z[20][20];
const int pattern[4][2][2] = { 
	{{0,1},{1,1}},
	{{1,0},{1,1}}, 
	{{1,0},{1,-1}}, 
	{{1,0},{0,1}}, //{0,1} {1,0} ����
};
int F(int z[][20]) {
	int ret = 0;
	int i, j, k;
	int x = -1, y = -1;
	//������ ã��
	for (i = 0; i < H; i++) {
		for (j = 0; j < W; j++) {
			if (z[i][j] == 0) {	//���
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	//�������
	if (y == -1) {
		return 1;
	}
	//���� ����
	for (k = 0; k < 4; k++) {
		if (z[y + pattern[k][0][0]][x + pattern[k][0][1]] == 0 && z[y + pattern[k][1][0]][x + pattern[k][1][1]] == 0 && y + pattern[k][0][0] < H && y + pattern[k][1][0] < H && x + pattern[k][0][1] < W && x + pattern[k][1][1] < W) {	//�ٸ� ��ĭ�� ��ĭ
			//printf("{%d %d}{%d %d}{%d %d}\n",y, x, y+pattern[k][0][0], x+pattern[k][0][1], y+pattern[k][1][0], x+pattern[k][1][1]);
			z[y][x] = 1;
			z[y + pattern[k][0][0]][x + pattern[k][0][1]] = 1;
			z[y + pattern[k][1][0]][x + pattern[k][1][1]] = 1;
			ret += F(z);
			z[y][x] = 0;
			z[y + pattern[k][0][0]][x + pattern[k][0][1]] = 0;
			z[y + pattern[k][1][0]][x + pattern[k][1][1]] = 0;
		}
	}
	return ret;
}

int main() {
	int ret, C;
	int i, j, k;
	char c;
	scanf("%d", &C);
	for (k = 0; k < C; k++) {
		Wnum = 0;
		scanf("%d %d", &H, &W);
		getchar();
		for (i = 0; i < H; i++) {
			for (j = 0; j < W; j++) {
				scanf("%c", &c);
				//z[H][W] = c == '#' ? 1 : 0;	//1 : ����, 0 : �Ͼ�
				if (c == '#') {
					z[i][j] = 1;
				}
				else {
					z[i][j] = 0;
					Wnum++;
				}
			}
			getchar();
		}
		if (Wnum % 3 != 0) { printf("0\n"); continue; }

		ret = F(z);
		printf("%d\n", ret);
	}
	return 0;
}
