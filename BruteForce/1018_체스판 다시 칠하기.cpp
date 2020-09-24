#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int board[51][51];

int check(int x, int y) {
	int resultw = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (board[x + i][y + j] != 2)
						resultw++;
				}
				else {
					if (board[x + i][y + j] != 1)
						resultw++;
				}
			}
			else {
				if (j % 2 == 0) {
					if (board[x + i][y + j] != 1)
						resultw++;
				}
				else {
					if (board[x + i][y + j] != 2)
						resultw++;
				}
			}
		}
	}

	int resultb = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (board[x + i][y + j] != 1)
						resultb++;
				}
				else {
					if (board[x + i][y + j] != 2)
						resultb++;
				}
			}
			else {
				if (j % 2 == 0) {
					if (board[x + i][y + j] != 2)
						resultb++;
				}
				else {
					if (board[x + i][y + j] != 1)
						resultb++;
				}
			}
		}
	}

	return resultw < resultb ? resultw : resultb;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int min = 64;

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			char c;
			scanf("%c", &c);
			
			if (c == 'B')
				board[i][j] = 1;			//black 1
			else
				board[i][j] = 2;			//white 2
			
			
		}
		
	}

	int x = n - 8;
	int y = m - 8;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			int color = check(i, j);
			if (color < min)
				min = color;
		}
	}

	printf("%d", min);
}