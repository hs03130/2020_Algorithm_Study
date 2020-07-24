#pragma warning(disable:4996)
#include<stdio.h>

int button[10][5] = { {0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13} };
int clock[16];
int ret;
int check() {
	int i = 0;
	for (i = 0; i < 16; i++) {
		if (clock[i] != 12)
			return 0;
	}
	return 1;
}
void push(int i) {
	int cnt;
	int j;
	for (j = 0; j < sizeof(button[i]); j++) {
		clock[button[i][j]] = (clock[button[i][j]] + 3) % 12;
	}
}

int factorial(int n) {
	if (n == 10) {
		if(check())
	}

}

int main() {
	int count = 0;
	int i;
	for (i = 0; 0 < 16; i++) {
		scanf("%d", clock[i]); //3,6,9,12
	}
	

}