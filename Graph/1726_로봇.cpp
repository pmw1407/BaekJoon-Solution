#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

typedef struct {
	int x, y;
}direction;

direction dircon[5] = { {0, 0},  {0, 1}, {0, -1}, {1, 0}, {-1, 0} };			//1µ¿	   2¼­		3³²		4ºÏ

int maze[110][110];
bool visit[110][110][5];
int moves;
int m, n;
int order;

int start1, start2, startd;
int final1, final2, finald;

queue<pair<pair<int, int>, pair<int, int > > >q;

int bfs(){
	q.push({ {start1, start2}, {startd, order} });
	visit[start1][start2][startd] = true;

	while (!q.empty()) {
		int a = q.front().first.first;
		int b = q.front().first.second;
		int d = q.front().second.first;
		int o = q.front().second.second;
		q.pop();

		if (a == final1 && b == final2 && d == finald)
			return o;

		for (int i = 1; i < 4; i++) {
			int next_a = a + i * dircon[d].x;
			int next_b = b + i * dircon[d].y;

			if (visit[next_a][next_b][d])
				continue;

			if (0 <= next_a && next_a < m && 0 <= next_b && next_b < n && maze[next_a][next_b] == 0) {
				visit[next_a][next_b][d] = true;
				q.push({ {next_a, next_b}, {d, o + 1} });
			}

			else
				break;
		}

		for (int i = 1; i < 5; i++) {
			if (d != i && visit[a][b][i] == false) {
				visit[a][b][i] = true;
				if (d + i == 3 || d + i == 7)
					q.push({ {a, b}, {i, o + 2} });
				else
					q.push({ {a, b}, {i, o + 1} });
			}
		}
	}

	return -1;
}

int main(void) {
	scanf("%d %d", &m, &n);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			maze[i][j] = temp;
		}
	}

	scanf("%d %d %d", &start1, &start2, &startd);
	scanf("%d %d %d", &final1, &final2, &finald);

	start1 -= 1; start2 -= 1; final1 -= 1; final2 -= 1;
	printf("%d\n", bfs());
}