#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int ,int> > graph[1010];
priority_queue<pair<int, int> > pq;
int n, m;
int INF = 987654321;

vector<int> daijkstra(int start, int destination) {
	vector<int> cost(n + 1, INF);
	cost[start] = 0;
	pq.push({ 0, start });									//cost, vertex

	while (!pq.empty()) {
		int temp_cost = -pq.top().first;
		int temp_v = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[temp_v].size(); i++) {
			int next_d = graph[temp_v][i].first;
			int next_cost = graph[temp_v][i].second;

			if (cost[next_d] > temp_cost + next_cost) {
				cost[next_d] = temp_cost + next_cost;
				pq.push({ -cost[next_d], next_d });
			}
		}
	}
	return cost;
}

int main(void) {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(make_pair(b, c));
	}
	int start, destination;
	scanf("%d %d", &start, &destination);

	vector<int> result = daijkstra(start, destination);

	printf("%d\n", result[destination]);
}