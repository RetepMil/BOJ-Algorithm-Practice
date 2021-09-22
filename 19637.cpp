#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, string> P;

map<int, string> category;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;

	cin >> N >> M;

	string temp;
	int point;
	int last_use = -1;
	for (int i = 0; i < N; i++) {
		cin >> temp >> point;
		if (point != last_use) category.insert(P(point, temp));
		else continue;
		last_use = point;
	}

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		cout << (category.lower_bound(a))->second << "\n";
	}

	return 0;
}