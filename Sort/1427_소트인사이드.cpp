#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int> > pq;

	while (n != 0) {
		pq.push(n % 10);
		n /= 10;
	}

	while (!pq.empty()) {
		cout << pq.top();
		pq.pop();
	}
}