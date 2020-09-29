#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int dist[401][401] = { 0 };
int v, e;
int INF = 1987654321;

int main(void) {
	scanf("%d %d", &v, &e);
	for (int i = 0; i <= 400; i++) {
		for (int j = 0; j <= 400; j++) {
			if (i == j)
				continue;
			dist[i][j] = INF;
		}
	}
	while (e--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dist[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int temp = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) 
				continue;
			if (dist[i][j] != INF && dist[j][i] != INF)
				temp = min(temp, dist[i][j] + dist[j][i]);
		}
	}

	printf(temp == INF ? "-1\n" : "%d\n", temp);
}