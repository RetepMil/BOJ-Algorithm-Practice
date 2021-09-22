#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int nine[9];
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> nine[i];
		sum += nine[i];
	}

	sort(nine, nine + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == j) continue;
			if ((sum - (nine[i] + nine[j])) == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << nine[k] << "\n";
				}
				return 0;
			}
		}
	}
}