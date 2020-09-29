#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, l;
int leak[1010];
bool taped[1010];

int main(void) {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		int loc;
		scanf("%d", &loc);
		leak[i] = loc;
	}
	sort(leak, leak + n);

	int tape = 1;
	int num = 1;
	for (int i = 0; i < n; i++) {
		if (tape <= l && i < n - 1) {
			tape = tape + leak[i + 1] - leak[i];
		}
		else if (tape > l) {
			tape = 1;
			i--;
			num++;
		}
	}

	printf("%d\n", num);
}