#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

queue<int> q;
vector<int> graph[20010];
bool visit[20010];
int d;
int qsize;
int hut[20010];
int index;

void bfs(int a) {
	visit[a] = true;
	q.push(a);
	while (!q.empty()) {
		qsize = q.size();
		for (int j = 0; j < qsize; j++) {
			int next = q.front(); q.pop();
			sort(graph[next].begin(), graph[next].end());
			for (int i = 0; i < graph[next].size(); i++) {
				int k = graph[next][i];
				if (visit[k] == false) {
					visit[k] = true;
					q.push(k);
					hut[index] = k;
					index++;
				}
			}
			
		}
		sort(hut, hut + index);
		index = 0;
		d++;
	}
	printf("%d %d %d\n",hut[0],d - 1, qsize);
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	bfs(1);
}