#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int n;
int classroom;
priority_queue<pair<int, int > > pq;
vector<pair<int, int> > time_table[200010];

int main(void) {
	scanf("%d", &n);
	while (n--) {
		int start;
		int finish;
		scanf("%d %d", &start, &finish);
		pq.push({ -start, -finish });
	}
	priority_queue<int, vector<int>, greater<int> > q;
	while (!pq.empty()) {
		int start = -pq.top().first;
		int end = -pq.top().second;
		pq.pop();
		if (q.empty())
			q.push(end);
		else {
			if (q.top() > start)
				q.push(end);
			else {
				q.pop();
				q.push(end);
			}
		}
	}
	printf("%d\n", q.size());
}