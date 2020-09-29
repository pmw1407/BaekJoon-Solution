#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, k;
int sensor[10010];
priority_queue<int, vector<int>, greater<int> > pq;

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sensor[i]);
	}
	sort(sensor, sensor + n);

	int max = 0;
	for (int i = 0; i < n - 1; i++) {
		int temp = sensor[i + 1] - sensor[i];
		if (temp == 0)
			continue;
		
		pq.push(temp);
	}
	int result = 0;
	if (k >= n)
		printf("%d\n", result);
	else {
		int cnt = pq.size() - k + 1;
		while (cnt--) {
			result += pq.top();
			pq.pop();
		}

		printf("%d\n", result);
	}
	
}