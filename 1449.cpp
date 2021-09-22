#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> list;
	int n, L;
	int asd;
	cin >> n >> L;

	int num;
	asd = n;
	while (n--) {
		cin >> num;
		list.push_back(num);
	}
	sort(list.begin(), list.end());

	int cnt = 1;
	int until = list[0] + L - 1;
	for (int i = 1; i < asd; i++) {
		if (list[i] > until) {
			until = list[i] + L - 1;
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}