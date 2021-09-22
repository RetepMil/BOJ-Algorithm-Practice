#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M, I;
vector<vector<int>> map;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> I;

	map.resize(N, vector<int>(M));

	int minHeight = 64, maxHeight = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			minHeight = min(minHeight, map[i][j]);
			maxHeight = max(maxHeight, map[i][j]);
		}
	}

	int shortest = 256 * 2 * N * M; int height = minHeight;
	for (int i = minHeight; i <= maxHeight; i++) {
		int down = 0, up = 0;

		for (int a = 0; a < N; a++) {
			for (int b = 0; b < M; b++) {
				int diff = map[a][b] - i;

				if (diff > 0) down += diff;
				else if (diff < 0) up += (-1 * diff);
			}
		}

		if (up > down + I) continue;
		if ((up + 2 * down) <= shortest) {
			height = i;
			shortest = up + 2 * down;
		}
	}

	printf("%d %d\n", shortest, height);

	return 0;
}