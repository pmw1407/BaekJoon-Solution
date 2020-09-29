#include<stdio.h>
#include<vector>

using namespace std;

int length, width, height;
int n;
vector<int> cube[20];

int getlength(int i) {
	int a = 1;
	while (i >= 1) {
		a *= 2;
		i--;
	}
	return a;
}

int& getMin(int &a, int &b, int &c) {
	int &x = a < b ? a : b;
	int &y = b < c ? b : c;
	return x < y ? x : y;
}

int getcube(int a) {
	for (int i = 0; getlength(i) <= a; i++) {
		if (getlength(i + 1) > a) {
			if (cube[i].empty()) {
				return getcube(i);
			}
			else
				return i;
		}
	}
}

int main(void) {
	int result = -1;

	scanf("%d %d %d", &length, &width, &height);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		cube[a].push_back(b);
	}

	int &min = getMin(length, width, height);
	int m_length = getcube(min);
	
	if (getlength(m_length) < min) {

	}

	//printf("%d", min);
	printf("%d", m_length);
}