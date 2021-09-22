#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];

	int closest = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int med = list[i] + list[j] + list[k];
				if (m - med < m - closest && (m - med) >= 0) {
					closest = med;
				}
			}
		}
	}

	cout << closest;

	return 0;
}