#include<stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	int result = 0;
	int min = n;
	for (int i = n / 2; i < n; i++) {
		result = i;
		int temp = i;

		while (temp != 0) {
			result += temp % 10;
			temp /= 10;
		}

		if (result == n && i < min)
			min = i;
	}

	if (min != n)
		printf("%d", min);
	else
		printf("%d\n", 0);
}