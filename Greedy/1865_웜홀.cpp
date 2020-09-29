#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

int n, m, w;
int INF = 1987654321;


int main(void) {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &n, &m, &w);
		vector<int> dist(n + 1, INF);
		vector<pair<int, int> > graph[510];
		bool cycle = false;
		while (m--) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({ e, t });
			graph[e].push_back({ s, t });
		}
		while (w--) {
			int s, e, t;
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({ e, -t });
		}

		dist[1] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (auto& temp : graph[j]) {
					int next_v = temp.first;
					int next_c = temp.second;
					if (dist[next_v] > dist[j] + next_c) {
						dist[next_v] = dist[j] + next_c;
						if (i == n)
							cycle = true;
					}
				}
			}
		}

		if (cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}
}