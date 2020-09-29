#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

int n, k;
int s;
int plug[110];
int consent[110];

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &consent[i]);
	}

	for (int i = 0; i < k; i++) {
		int temp = consent[i];
		bool sw = false;
		for (int j = 0; j < n; j++) {
			if (plug[j] == consent[i]) {
				sw = true;
				break;
			}
		}
		if (sw)
			continue;

		for (int j = 0; j < n; j++) {
			if (plug[j] == 0) {
				plug[j] = consent[i];
				sw = true;
				break;
			}
		}

		if (sw)
			continue;

		int index, device = -1;
		for (int j = 0; j < n; j++) {
			int last = 0;
			for (int a = i + 1; a < k; a++) {
				if (plug[j] == consent[a])
					break;
				last++;
			}

			if (last > device) {
				index = j;
				device = last;
			}
		}
		s++;
		plug[index] = consent[i];
	}

	printf("%d\n", s);
}