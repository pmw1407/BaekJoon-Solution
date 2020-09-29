#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int t, n, m, k;
vector<pair<int, pair<int, int > > > graph[110];
priority_queue < pair<int, pair<int, int> > > pq;
int cost[110];
int INF = 1987654321;

void daijkstra() {
	priority_queue<int, vector<int>, greater<int> > q;
	cost[1] = 0;
	pq.push({ 0, {1, 0} });
	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_v = pq.top().second.first;
		int temp_m = pq.top().second.second;
		//printf("%d ", temp_v);
		pq.pop();

		for (int i = 0; i < graph[temp_v].size(); i++) {
			int next_v = graph[temp_v][i].first;
			int next_c = graph[temp_v][i].second.second;
			int next_m = graph[temp_v][i].second.first;
			if (temp_m + next_m <= m) {
				if (cost[next_v] == INF) {
					if (next_v == n)
						q.push(temp_c + next_c);
					else
						pq.push({ -(next_c + temp_c), {next_v, temp_m + next_m} });
				}
			}
		}
	}
	if (q.empty())
		printf("Poor KCM\n");
	else
		printf("%d\n", q.top());
}

int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		while (k--) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back({ v, {c, d} });
		}
		
		for (int i = 1; i <= n; i++) {
			cost[i] = INF;
		}
		daijkstra();
		for (int i = 0; i <= n; i++) {
			graph[i].clear();
		}
	}
	
}