#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

int n, k;
vector<int> coin;
int sum;

int main(void) {
	scanf("%d %d", &n, &k);
	while (n--) {
		int a;
		scanf("%d", &a);
		coin.push_back(a);
	}

	for (int i = coin.size() - 1; i >= 0; i--) {
		if (k / coin[i] == 0)
			continue;

		else {
			int temp = k / coin[i];
			sum += temp;
			k = k % coin[i];
		}
	}

	printf("%d\n", sum);
}