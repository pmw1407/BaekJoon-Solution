#include<iostream>
#include<queue>
#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[10001];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		arr[t]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (arr[i] != 0) {
			while (arr[i]--) {
				printf("%d\n", i);
			}
		}
	}
}