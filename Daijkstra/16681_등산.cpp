#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

long long int n, m, d, e;

long long int INF = 987654321987654;
long long int height[100010];
vector<pair<long long int, long long int > > graph[100010];
long long int cost_up[100010];
long long int cost_down[100010];
long long int sum[100010];
bool visit[100010];


void daijkstra_up() {
	memset(visit, false, sizeof(visit));
	cost_up[1] = 0;
	priority_queue<pair<long long int, long long int> > pq;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		long long int temp_c = -pq.top().first;
		long long int temp_v;
		long long int temp_h;
		do {
			temp_v = pq.top().second;
			temp_h = height[temp_v];
			pq.pop();
		} while (!pq.empty() && visit[temp_v]);
		if (visit[temp_v])break;
		visit[temp_v] = true;

		for (long long int i = 0; i < graph[temp_v].size(); i++) {
			long long int next_v = graph[temp_v][i].first;
			long long int next_c = graph[temp_v][i].second;
			long long int next_h = height[next_v];
			if (next_h > temp_h && cost_up[next_v] > temp_c + next_c) {
				cost_up[next_v] = temp_c + next_c;
				pq.push({ -cost_up[next_v], next_v });
			}
		}
	}
}

void daijkstra_down() {
	memset(visit, false, sizeof(visit));
	cost_down[n] = 0;
	priority_queue<pair<long long int, long long int> > pq;
	pq.push({ 0, n });
	while (!pq.empty()) {
		long long int temp_c = -pq.top().first;
		long long int temp_v;
		long long int temp_h;
		do {
			temp_v = pq.top().second;
			temp_h = height[temp_v];
			pq.pop();
		} while (!pq.empty() && visit[temp_v]);

		for (long long int i = 0; i < graph[temp_v].size(); i++) {
			long long int next_v = graph[temp_v][i].first;
			long long int next_c = graph[temp_v][i].second;
			long long int next_h = height[next_v];
			if (next_h > temp_h && cost_down[next_v] > temp_c + next_c) {
				cost_down[next_v] = temp_c + next_c;
				pq.push({ -cost_down[next_v], next_v });
			}
		}
	}
}

int main(void) {
	scanf("%lld %lld %lld %lld", &n, &m, &d, &e);
	for (long long int i = 1; i <= n; i++) {
		long long int h;
		scanf("%lld", &h);
		height[i] = h;
	}
	while (m--) {
		long long int a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++) {
		cost_up[i] = INF;
		cost_down[i] = INF;
	}

	daijkstra_up();
	daijkstra_down();

	long long int max = -INF;
	for (long long int i = 2; i < n; i++) {
		if (cost_up[i] == INF || cost_down[i] == INF)
			continue;
		sum[i] = height[i] * e - (cost_up[i] + cost_down[i]) * d;
		if (max < sum[i]) {
			max = sum[i];
		}
	}
	if (max == -INF)
		printf("Impossible\n");
	else
		printf("%lld\n", max);
}