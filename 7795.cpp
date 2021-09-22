#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int univ;

bool cmp(int a) {
	return a < univ;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;

	while (n--) {
		int asize, bsize;
		int cnt = 0;
		cin >> asize >> bsize;
		
		int num;
		while (asize--) {
			cin >> num;
			a.push_back(num);
		}
		while (bsize--) {
			cin >> num;
			b.push_back(num);
		}

		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());

		for (int i : a) {
			univ = i;
			auto it = find_if(b.begin(), b.end(), cmp);
			cnt += b.end() - it;
		}

		a.clear();
		b.clear();

		cout << cnt << "\n";
	}

	return 0;
}