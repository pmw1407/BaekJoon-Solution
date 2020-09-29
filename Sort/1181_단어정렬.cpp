#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

vector<pair<int, string> > dictionary;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	while (n--) {
		string word;
		cin >> word;
		int size = word.size();
		dictionary.push_back({ size, word });
	}

	sort(dictionary.begin(), dictionary.end());

	for (int i = 0; i < dictionary.size(); i++) {
		if (i > 0 && dictionary[i - 1].second.compare(dictionary[i].second) == 0)
			continue;

		cout << dictionary[i].second << "\n";
	}
}