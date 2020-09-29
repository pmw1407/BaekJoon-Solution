#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int hw[1010];

priority_queue<pair<int, int> > pq;

int main(void) {
	scanf("%d", &n);
	while (n--) {
		int d, w;
		scanf("%d %d", &d, & w);
		pq.push({ w, d });
	}

	while (!pq.empty()) {
		int temp_s = pq.top().first;
		int temp_d = pq.top().second;
		pq.pop();
		while (temp_d >= 1) {
			if (hw[temp_d] == 0) {
				hw[temp_d] = temp_s;
				break;
			}
			else
				temp_d--;
		}
	}

	int total = 0;
	for (int i = 1; i <= 1009; i++) {
		if (hw[i] != 0) {
			total += hw[i];
		}
	}

	printf("%d\n", total);
}