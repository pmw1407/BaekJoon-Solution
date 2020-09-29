#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<pair<int, string> > v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return false;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int idx = 0;

	while (n--) {
		int age;
		string name;

		cin >> age >> name;
		idx++;
		v.push_back({ age, name });
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < idx; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}