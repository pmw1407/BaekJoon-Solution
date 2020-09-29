#include<stdio.h>
#include<iostream>
#include<algorithm>


using namespace std;

int arr[500010];
int elem[8001];
int m[2];

int main(void) {
	int n;
	scanf("%d", &n);

	int arith_mean = 0;
	int mid_val;
	int rep;
	int range;

	int max = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arith_mean += arr[i];
		elem[arr[i] + 4000]++;
	}

	int idx = 0;

	for (int i = 0; i < 8001; i++) {
		if (max < elem[i]) 
			max = elem[i];
	}

	for (int i = 0; i < 8001; i++) {
		if (elem[i] == max) {
			m[idx] = i - 4000;
			idx++;
		}

		if (idx == 2)
			break;
	}
	
	if (idx == 2)
		rep = m[1];
	else
		rep = m[0];

	sort(arr, arr + n);

	mid_val = arr[n / 2];
	range = arr[n - 1] - arr[0];

	if (arith_mean < 0) {
		if (arith_mean % n < -n / 2)
			arith_mean = arith_mean / n - 1;
		else
			arith_mean = arith_mean / n;
	}

	else {
		if (arith_mean % n > n / 2)
			arith_mean = arith_mean / n + 1;
		else
			arith_mean = arith_mean / n;
	}

	printf("%d\n", arith_mean);
	printf("%d\n", mid_val);
	printf("%d\n", rep);
	printf("%d\n", range);
}