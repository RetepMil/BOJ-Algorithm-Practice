#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int> &x, const vector<int>& y) {
	if (x[0] < y[0])
		return true;
	else if (x[0] == y[0])
		return (x[1] < y[1]);
	else
		return false;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);

	vector<vector<int>> coord;
	int n;
	vector<int> input(2);

	cin >> n;
	
	while (n--) {
		cin >> input[0] >> input[1];
		coord.push_back(input);
	}

	sort(coord.begin(), coord.end(), compare);

	for (vector<int> i : coord) cout << i[0] << " " << i[1] << "\n";

	return 0;
}