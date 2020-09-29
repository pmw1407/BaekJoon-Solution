#include<stdio.h>
#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;

int N, M;
vector<pair<int, int> > graph[510];
int dist[510];
int INF = 2e9;
int cycle = 0;

void bellman() {
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto& temp : graph[j]) {
				int next_v = temp.first;
				int next_c = temp.second;
				if (dist[j] != INF && dist[next_v] > dist[j] + next_c) {
					dist[next_v] = dist[j] + next_c;
					if (i == N)
						cycle = -1;
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	while (M--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b, c });
	}

	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	bellman();
	if (cycle == -1)
		printf("-1\n");
	else {
		int k = -1;
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
}