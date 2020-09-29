#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int maze[110][110];
bool visit[110][110];

int moves = 1;
int n, m;

queue<pair<int, int> > q;

void bfs(int a, int b) {
	visit[a][b] = true;

	q.push({ a, b });

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			pair<int, int> temp = q.front(); q.pop();
			int j = temp.first;
			int k = temp.second;
			
			if (j > 1 && visit[j - 1][k] == false) {		//위
				q.push({ j - 1, k });
				visit[j - 1][k] = true;
			}

			if (k > 1 && visit[j][k - 1] == false) {		//왼쪽
				q.push({ j, k - 1 });
				visit[j][k - 1] = true;
			}

			if (j < n && visit[j + 1][k] == false) {		//아래쪽
				q.push({ j + 1, k });
				visit[j + 1][k] = true;
			}
			if (k < m && (visit[j][k + 1]) == false) {		//오른쪽
				q.push({ j, k + 1 });
				visit[j][k + 1] = true;
			}
			if (j == n && k == m) {
				return;
			}
		}

		moves++;
		
	}
}

int main(void) {
	scanf("%d %d", &n, &m);

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			int temp[110];
			scanf("%1d", &temp[j]);
			maze[i][j] = temp[j];
			
			if (temp[j] == 1)
				visit[i][j] = false;
			else
				visit[i][j] = true;

		}
		
	}

	bfs(1, 1);

	printf("%d\n", moves);
}