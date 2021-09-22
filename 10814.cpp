#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comparator(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<pair<int, string>> list;
	string str;
	int age;

	for (int i = 0; i < n; i++) {
		cin >> age >> str;
		list.push_back(make_pair(age, str));
	}

	stable_sort(list.begin(), list.end(), comparator);

	for (auto i : list) cout << i.first << " " << i.second << "\n";

	return 0;
}