#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int> list(n);
	for (int i = 0; i < n; i++)
		cin >> list[i];

	sort(list.begin(), list.end());

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		int low = 0, high = list.size() - 1;
		bool check = false;

		while (low <= high) {
			int mid = (low + high) / 2;

			if (list[mid] == num) {
				check = true;
				break;
			}
			else if (list[mid] < num)
				low = mid + 1;
			else
				high = mid - 1;
			
		}
		cout << (check ? 1 : 0) << " ";
	}


	return 0;
}