#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int time[11];
int verdict[11];
int penalty;

int main(void) {
	
	for (int i = 0; i < 11; i++) {
		int d, v;
		scanf("%d %d", &d, &v);
		time[i] = d;
		verdict[i] = v;
	}
	sort(time, time + 11);
	int total_t = 0;
	for (int i = 0; i < 11; i++) {
		total_t += time[i];
		penalty += total_t + verdict[i] * 20;
	}

	printf("%d\n", penalty);
}