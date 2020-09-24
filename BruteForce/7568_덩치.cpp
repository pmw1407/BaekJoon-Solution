#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int board[51];

vector<pair<int, int> > big;

int main(void) {
	int idx = 0;
	int n;
	scanf("%d", &n);
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);

		int ladder = 1;
		
		for (int i = 0; i < big.size(); i++) {
			int tempx = big[i].first - x;
			int tempy = big[i].second - y;

			if (tempx > 0 && tempy > 0) {
				ladder++;
			}
			
			else if (tempx < 0 && tempy < 0) {
				board[i]++;
			}
		}
		board[idx] = ladder;
		idx++;
		big.push_back({ x, y });
	}

	for (int i = 0; i < idx; i++)
		printf("%d ", board[i]);
}