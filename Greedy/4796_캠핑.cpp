#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int l, p, v;

int main(void) {
	int test_case = 1;
	while (true) {
		scanf("%d %d %d", &l, &p, &v);
		if (l == 0 && p == 0 && v == 0)
			break;
		int camp;
		camp = v % p < l ? v % p : l;
		printf("Case %d: %d\n", test_case, l * (v / p) + camp);
		test_case++;
	}
}