#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int conf;
int n;
priority_queue<pair<int, int> > pq;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int start, finish;
		scanf("%d %d", &start, &finish);
		pq.push({ -finish, -start });
	}

	while (!pq.empty()) {
		int start = -pq.top().second;
		int finish = -pq.top().first;
		pq.pop();
		while (!pq.empty() && -pq.top().second < finish) {
			pq.pop();
		}
		conf++;
	}

	printf("%d\n", conf);
}