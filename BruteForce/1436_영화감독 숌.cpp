#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int idx = 0;
	int result = 666;

	for (int i = 666;; i++) {
		int temp = i;
		int stack = 0;
		
		while (temp != 0) {
			int digit = temp % 10;
			if (digit == 6)
				stack++;
			else
				stack = 0;

			if (stack == 3) {
				idx++;
				break;
			}
			temp /= 10;
		}

		if (n == idx) {
			result = i;
			break;
		}
	}
	printf("%d", result);
}