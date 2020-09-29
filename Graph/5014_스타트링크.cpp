#include<stdio.h>
#include<queue>
#include<iostream>

using namespace std;

int f, s, g, u, d;
int moves;

vector<int> visit;
queue<int> q;

void bfs() {
	q.push(s);
	visit[s] = 1;

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {

			int temp = q.front(); q.pop();
			if (temp == g) {
				printf("%d\n", visit[temp] - 1);
				return;
			}

			if (temp + u <= f && u != 0) {
				if (visit[temp + u] == 0) {
					q.push(temp + u);
					visit[temp + u] = visit[temp] + 1;
				}
			}
			else if (temp - d >= 1 && d != 0) {
				if (visit[temp - d] == 0) {
					q.push(temp - d);
					visit[temp - d] = visit[temp] + 1;
				}
			}
		}

		
	}
	printf("use the stairs\n");
}

int main(void) {
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	visit.assign(f + 1, 0);

	bfs();
}