#include<stdio.h>
#include<iostream>

using namespace std;

int card[101];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}

	int max = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = card[i] + card[j] + card[k];
				if (temp > max&& temp <= m)
					max = temp;
			}
		}
	}

	printf("%d", max);
}