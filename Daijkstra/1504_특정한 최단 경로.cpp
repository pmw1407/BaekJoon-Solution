#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > graph[810];
priority_queue<pair<int, int> > pq;
int n, e;
int INF = 987654321;

vector<int> daijkstra(int start) {
	vector<int> cost(n + 1, INF);
	cost[start] = 0;
	pq.push(make_pair(0, start));					//cost, vertex

	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_v = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[temp_v].size(); i++) {
			int next_c = cost[temp_v] + graph[temp_v][i].second;
			int next_v = graph[temp_v][i].first;
			if (cost[next_v] > next_c) {
				cost[next_v] = next_c;
				pq.push({ -next_c, next_v });
			}
		}
	}
	return cost;
}

int main(void) {
	scanf("%d %d", &n, &e);
	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int must_a, must_b;
	scanf("%d %d", &must_a, &must_b);

	vector<int> A = daijkstra(must_a);
	vector<int> B = daijkstra(must_b);
	vector<int> result = daijkstra(1);

	int atob = A[must_b];
	int btoa = B[must_a];

	if (atob == INF || btoa == INF || result[n] == INF || B[n] == INF || A[n] == INF)
		printf("%d\n", -1);

	else {
		int shortest = result[must_a] + atob + B[n] >= result[must_b] + btoa + A[n] ? result[must_b] + btoa + A[n] : result[must_a] + atob + B[n];
		printf("%d\n", shortest);
	}
}