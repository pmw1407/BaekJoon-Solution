#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q;
vector<int> graph[1010];
bool visit[1010];

void dfs(int a) {
	printf("%d ", a);
	visit[a] = true;
	sort(graph[a].begin(), graph[a].end());

	for (int i = 0; i < graph[a].size(); i++) {
		
		int next = graph[a][i];

		if (visit[next] == false)
			dfs(next);
	}
}

void bfs(int a) {
	printf("%d ", a);
	visit[a] = true;
	q.push(a);
	while (!q.empty()) {
		int next = q.front(); q.pop();
		sort(graph[next].begin(), graph[next].end());
		for (int i = 0; i < graph[next].size(); i++) {
			int k = graph[next][i];
			if (visit[k] == false) {
				visit[k] = true;
				printf("%d ", k);
				q.push(k);
			}
		}
	}
	
}

int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);
		
	}

	dfs(v);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(v);
	printf("\n");
}