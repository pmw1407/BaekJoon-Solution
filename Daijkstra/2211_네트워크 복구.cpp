#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<pair<int, int > > network[1010];
priority_queue<pair<int, int> > pq;			//cost, vertex
vector<int> cost;
int INF = 987654321;
int recover;
vector<pair<int, int> > re;

void daijkstra() {
	cost.assign(n + 1, INF);
	cost[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		int temp_c = -pq.top().first;
		int temp_v = pq.top().second;
		pq.pop();

		for (int i = 0; i < network[temp_v].size(); i++) {
			int next_v = network[temp_v][i].first;
			int next_c = temp_c + network[temp_v][i].second;

			if (cost[next_v] > next_c) {
				if (cost[next_v] == INF) {
					re.push_back({ temp_v, next_v });
					recover++;
				}
				else {
					for (int j = 0; j < recover; j++) {
						if (re[j].second == next_v) {
							re[j].first = temp_v;
						}
					}
				}
				cost[next_v] = next_c;
				pq.push({ -next_c, next_v });
			}
		}
	}
	printf("%d\n", recover);
}

int main(void) {
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		network[a].push_back({ b, c });
		network[b].push_back({ a, c });
	}
	daijkstra();

	for (int i = 0; i < recover; i++) {
		printf("%d %d\n", re[i].first, re[i].second);
	}
}