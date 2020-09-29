#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, x;
int INF = 987564321;

vector<pair<int, int> > village[1010];
priority_queue<pair<int, int> > pq;

vector<int> daijkstra(int start) {
	vector<int> cost(n + 1, INF);
	cost[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_v = pq.top().second;
		pq.pop();

		for (int i = 0; i < village[temp_v].size(); i++) {
			int next_v = village[temp_v][i].first;
			int next_c = village[temp_v][i].second;
			if (cost[next_v] > next_c + temp_c) {
				cost[next_v] = next_c + temp_c;
				pq.push({ -cost[next_v], next_v });
			}
		}
	}

	return cost;
}

int main(void) {
	scanf("%d %d %d", &n, &m, &x);
	while (m--) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		village[a].push_back(make_pair(b, t));
	}

	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		vector<int> result = daijkstra(i);
		int go = result[x];
		//printf("%d\n", go);
		result = daijkstra(x);
		int way_back = result[i];
		//printf("%d\n", way_back);
		q.push(go + way_back);
	}

	printf("%d\n", q.top());
}