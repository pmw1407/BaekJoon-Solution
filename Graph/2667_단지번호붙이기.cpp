#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int rain[30][30];
int numofhouse;
vector<int> houses;

void bfs(int i, int j, int n) {
	rain[i][j] = -1;
	numofhouse++;

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
				houses.push_back(numofhouse);

				numofhouse = 0;
			}
		}
	}

	return realm;
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < n; j++) {
			vector<int> house(n);
			scanf("%1d", &house[j]);
			rain[i][j] = house[j];
		}
	}

	int apartment = search(n);
	printf("%d\n", apartment);
	sort(houses.begin(), houses.end());
	for (int i = 0; i < apartment; i++) {
		printf("%d\n", houses[i]);
	}
}