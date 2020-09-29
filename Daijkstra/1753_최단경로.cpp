#include<stdio.h>
#include<queue>
#include<iostream>
#include<utility>

using namespace std;

vector<pair<int, int> > graph[20010];

int v, e;
int k;

const int INF = 987654321;

vector<int> daijkstra(int start) {
	vector<int> distance(v + 1, INF);
	distance[start] = 0;

	priority_queue<pair<int, int> > pq;				//비용, 정점
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int temp_v = pq.top().second;
		pq.pop();

		if (distance[temp_v] < dist)
			continue;
		for (int i = 0; i < graph[temp_v].size(); i++) {
			int adj = graph[temp_v][i].first;
			int adj_d = dist + graph[temp_v][i].second;

			if (distance[adj] > adj_d) {
				distance[adj] = adj_d;
				pq.push({ -adj_d, adj });
			}
		}
	}
	return distance;
}

int main(void) {
	scanf("%d %d %d", &v, &e, &k);

	while (e--) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		
		graph[a].push_back(make_pair(b, w));			//정점, 가중치
	}

	vector<int> result = daijkstra(k);

	for (int i = 1; i < v + 1; i++) {
		if (result[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", result[i]);
	}
}