#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int > > graph[50010];
vector<int> flight[50010];
long long int cost[50010][2];										//첫번째는 비행기 안씀 두번째는 비행기 씀
priority_queue<pair<pair<int, int>, int> > pq;			//cost, vertex, flight used or not

int n, m, f, s, t;
long long int INF = 2147483647;

bool check_flight(int a, int  b) {
	if (!flight[a].empty()) {
		for (int i = 0; i < flight[a].size(); i++) {
			if (flight[a][i] == b)
				return true;
		}
		return false;
	}

	else
		return false;
}

void daijkstra(int start) {
	cost[start][0] = 0;
	pq.push({ {0, start}, 0 });

	while (!pq.empty()) {
		int temp_c = -pq.top().first.first;
		int temp_v = pq.top().first.second;
		int temp_f = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[temp_v].size(); i++) {
			int next_v = graph[temp_v][i].first;
			int next_c = temp_c + graph[temp_v][i].second;

			if (temp_f == 0 && cost[next_v][0] >= next_c) {
				cost[next_v][0] = next_c;
				pq.push({ {-next_c, next_v}, 0 });
			}
			if (temp_f == 1 && cost[next_v][1] >= next_c) {
				cost[next_v][1] = next_c;
				pq.push({ {-next_c, next_v}, 1 });
			}
		}

		for (int j = 0; j < flight[temp_v].size(); j++) {
			int next_f = flight[temp_v][j];
			
			if (temp_f == 0 && cost[next_f][1] >= temp_c) {
				cost[next_f][1] = temp_c;
				pq.push({ {-temp_c, next_f}, 1 });
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
	while (m--) {
		int i, j, c;
		scanf("%d %d %d", &i, &j, &c);
		graph[i].push_back({ j, c });
		graph[j].push_back({ i, c });
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cost[i][j] = INF;
		}
	}

	while (f--) {
		int u, v;
		scanf("%d %d", &u, &v);
		flight[u].push_back(v);
	}

	daijkstra(s);
	long long int result = cost[t][0] >= cost[t][1] ? cost[t][1] : cost[t][0];

	printf("%lld\n", result);
}