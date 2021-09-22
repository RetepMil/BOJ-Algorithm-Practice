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

	sort(list.begin(), list.end());

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		int low = 0, high = list.size() - 1;
		int index = -1;

		while (low <= high) {
			int mid = (low + high) / 2;
			
			if (list[mid] < num)
				low = mid + 1;
			else
				high = mid - 1;

			if (list[mid] == num) {
				index = mid;
			}

		}
		cout << index << " ";
	}


	return 0;
}