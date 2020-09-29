#include<stdio.h>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> computer[10010];
bool color[10010];
int maximum;
int real_max;

void dfs(int a) {
	color[a] = true;				//gray
	
	for (int i = 0; i < computer[a].size(); i++) {
		int k = computer[a][i];

		if (color[k] == false) {
			maximum++;
			dfs(k);
		}
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> answer;

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		computer[b].push_back(a);			//hackable directed graph
	}

	for (int i = 1; i < n; i++) {
		memset(color, false, sizeof(color));
		maximum = 0;
		dfs(i);
				
		if (maximum == real_max)
			answer.push_back(i);
		else if (real_max < maximum) {
			real_max = maximum;
			answer.clear();
			answer.push_back(i);
		}
	}

			

	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	printf("\n");
}