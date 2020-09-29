#include<iostream>
#include<queue>
#include<stdio.h>

using namespace std;

priority_queue<pair<int, int> > pq;

int main(void) {
	int n;
	cin >> n;

	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		pq.push({ -y, -x });
	}

	while (!pq.empty()) {
		int y = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		printf("%d %d\n", -x, -y);
	}
}