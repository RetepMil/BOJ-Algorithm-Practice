#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[11];
int operations[4];
int N;
int maxv = -2000000000;
int minv = 2000000000;

void dfs(int depth, int value) {
	if (depth == N) {
		if (value > maxv)
			maxv = value;
		if (value < minv)
			minv = value;
		return;
	} else {
		for (int i = 0; i < 4; i++) {
			if (operations[i] > 0) {
				operations[i]--;
				switch (i) {
					case 0:
						dfs(depth + 1, value + arr[depth]);
						break;
					case 1:
						dfs(depth + 1, value - arr[depth]);
						break;
					case 2:
						dfs(depth + 1, value * arr[depth]);
						break;
					case 3:
						dfs(depth + 1, value / arr[depth]);
						break;
				}
				operations[i]++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++) {
		cin >> operations[i];
	}

	dfs(1, arr[0]);

	cout << maxv << "\n" << minv << "\n";

	return 0;
}