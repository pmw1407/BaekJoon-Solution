#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct {
	int x, y;
}direction;

direction dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int maze[110][110];
int cost[110][110];
int INF = 987654321;
int m, n;
priority_queue<pair<int,pair<int,int> > > pq;

void daijkstra() {
	cost[0][0] = 0;
	pq.push({ 0, {0, 0} });
	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_x = pq.top().second.first;
		int temp_y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = temp_x + dir[i].x;
			int next_y = temp_y + dir[i].y;
			int next_c = maze[next_x][next_y];
			if (0 <= next_x && next_x < m && 0 <= next_y && next_y < n) {
				if (maze[next_x][next_y] == 0) {
					if (cost[next_x][next_y] > next_c + temp_c) {
						cost[next_x][next_y] = next_c + temp_c;
						pq.push({ -cost[next_x][next_y], {next_x, next_y} });
					}
				}
				else {
					if (cost[next_x][next_y] > next_c + temp_c) {
						cost[next_x][next_y] = next_c + temp_c;
						pq.push({ -cost[next_x][next_y], {next_x, next_y} });
					}
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int temp[110];
			scanf("%1d", &temp[j]);
			maze[i][j] = temp[j];
			cost[i][j] = INF;
		}
	}

	daijkstra();

	printf("%d\n", cost[m - 1][n - 1]);
}