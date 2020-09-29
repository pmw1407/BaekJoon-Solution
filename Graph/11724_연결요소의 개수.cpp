#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> graph[1010];
bool visit[1010];

void dfs(int a) {
	visit[a] = true;

	for (int i = 0; i < graph[a].size(); i++) {
		int next = graph[a][i];

		if (visit[next] == false)
			dfs(next);
	}
}

int main(void) {
	int n, m;
	int set = 0;
	scanf("%d %d", &n, &m);

	memset(visit, false, sizeof(visit));

	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i < n + 1; i++) {
		if (!graph[i].empty() && visit[i] == false) {
			dfs(i);
			set++;
		}
		else if (graph[i].empty())
			set++;
	}

	printf("%d\n", set);
}