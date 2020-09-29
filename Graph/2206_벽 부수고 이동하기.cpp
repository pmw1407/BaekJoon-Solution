#include<stdio.h>
#include<iostream>
#include<queue>
#define MAX 1010
using namespace std;

int maze[MAX][MAX];
bool visit[MAX][MAX][2];

int n, m;
bool wall = true;

typedef struct {
	int x, y;
}direction;

direction dir[5] = { {0, 0},  {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

queue<pair<pair<int ,int>, pair<int, int> > > q;

int bfs() {
	q.push({ {0, 0}, {0, 1} });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int brk = q.front().second.first;
		int moves = q.front().second.second;
		q.pop();

		if (a == n - 1 && b == m - 1) {
			return moves;
		}
		for (int i = 1; i < 5; i++) {
			int next_a = a + dir[i].x;
			int next_b = b + dir[i].y;

			if (0 <= next_a && next_a < n && 0 <= next_b && next_b < m) {
				if (maze[next_a][next_b] == 1 && brk == 0) {
					visit[next_a][next_b][brk + 1] = true;
					q.push({ {next_a, next_b}, {brk + 1, moves + 1} });
				}

				else if (maze[next_a][next_b] == 0 && visit[next_a][next_b][brk] == false) {
					visit[next_a][next_b][brk] = true;
					q.push({ {next_a, next_b}, {brk, moves + 1} });
				}
			}
		}
	}
	return -1;
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int temp[1000];
			scanf("%1d", &temp[j]);

			maze[i][j] = temp[j];
		}
	}		

	int sol = bfs();

	printf("%d\n", sol);
}