#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int cave[130][130];
int cost[130][130];
int INF = 987654321;
int n = 1;

priority_queue <pair<int, pair<int, int> > > pq;

typedef struct {
	int x, y;
}dir;

dir direction[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };		//µ¿ ³² ¼­ ºÏ

void daijkstra() {
	cost[0][0] = cave[0][0];
	pq.push({ -cost[0][0], {0, 0} });
	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_x = pq.top().second.first;
		int temp_y = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = temp_x + direction[i].x;
			int next_y = temp_y + direction[i].y;
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
				if (cost[next_x][next_y] > temp_c + cave[next_x][next_y]) {
					cost[next_x][next_y] = temp_c + cave[next_x][next_y];
					pq.push({ -cost[next_x][next_y],{next_x, next_y} });
				}
			}
		}
	}
	
}

int main(void) {
	int i = 1;
	
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			return 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int a;
				scanf("%d", &a);
				cave[i][j] = a;
			
				cost[i][j] = INF;
				
			}

		}

		daijkstra();
		printf("Problem %d: %d\n", i,cost[n - 1][n - 1]);
		for (int i = 0; i < 130; i++) {
			for (int j = 0; j < 130; j++) {
				cave[i][j] = 0;
				cost[i][j] = INF;
			}
		}
		i++;
	}
}