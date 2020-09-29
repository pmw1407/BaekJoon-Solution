#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

long long int L, N, rf, rb;
priority_queue<pair<long long int, long long int> > pq;

int main(void) {
	scanf("%lld %lld %lld %lld", &L, &N, &rf, &rb);

	for (int i = 0; i < N; i++) {
		long long int x, c;
		scanf("%lld %lld", &x, &c);
		pq.push({ c, x });
	}

	long long int delta_v = rf - rb;
	long long int result = 0;
	long long int c = pq.top().first;
	long long int d = pq.top().second;
	pq.pop();
	result += delta_v * d * c;
	//printf("%d\n", result);

	while (!pq.empty()) {
		long long int temp_c = pq.top().first;
		long long int temp_d = pq.top().second;
		pq.pop();
		if (temp_d < d)
			continue;
		result += delta_v * (temp_d - d) * temp_c;
		//printf("%d\n", result);
		d = temp_d;
	}

	printf("%lld\n", result);
}