#include<stdio.h>
#include<queue>
#include<iostream>

using namespace std;

int graph[110][110];
int rain[110][110];
int max_realm;

void bfs(int i, int j, int n) {
	rain[i][j] = -1;

	if (i > 0 && rain[i - 1][j] == 1)
		bfs(i - 1, j, n);
	if (j > 0 && rain[i][j - 1] == 1)
		bfs(i, j - 1, n);
	if (i < n - 1 && rain[i + 1][j] == 1)
		bfs(i + 1, j, n);
	if(j < n - 1 && rain[i][j + 1] == 1)
		bfs(i, j + 1, n);
}

int search(int n) {
	int realm = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (rain[i][j] == 1) {
				bfs(i, j, n);
				realm++;
			}
		}
	}

	return realm;
}

int main(void) {
	int max = 0, min = 0;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int height;
			scanf("%d", &height);
			if (max < height)
				max = height;

			graph[i][j] = height;
			if (j == 0 && i == 0)
				min = height;

			if (min > height)
				min = height;

		}
	}

	

	for (int k = min - 1; k < max; k++) {
		for (int l = 0; l < n; l++) {
			for (int m = 0; m < n; m++) {
				int x = graph[l][m];
				if (x <= k)
					rain[l][m] = -1;			//drown
				else
					rain[l][m] = 1;		//safe

				
			}
			
		}
		
		int a = search(n);
		if (max_realm < a)
			max_realm = a;


	}

	printf("%d\n", max_realm);
}