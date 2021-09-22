#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int T;

string solve(int N) {
	vector<pair<int, int>> locations;
	vector<vector<bool>> canGoBetween(N + 2, vector<bool>(N + 2, false));

	for (int i = 0; i < N + 2; i++) {
		int x, y; cin >> x >> y;
		locations.push_back(make_pair(x, y));
		canGoBetween[i][i] = true;
	}

	// √ ±‚»≠
	for (int i = 0; i < N + 2; i++) {
		for (int j = i + 1; j < N + 2; j++) {
			int x_dist = abs(locations[i].first - locations[j].first);
			int y_dist = abs(locations[i].second - locations[j].second);
			if (x_dist + y_dist <= 1000)
				canGoBetween[i][j] = canGoBetween[j][i] = true;

		}
	}

	//Floyd-Warshall
	for (int k = 0; k < N + 2; k++) {
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				if (canGoBetween[i][k] && canGoBetween[k][j])
					canGoBetween[i][j] = true;
			}
		}
	}

	return (canGoBetween[0][N + 1] ? "happy\n" : "sad\n");
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N; cin >> N;
		cout << solve(N);
	}

	return 0;
}