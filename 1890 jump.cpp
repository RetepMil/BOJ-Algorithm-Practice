#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long long grid[100][100] = { 0, };
long long dp[100][100] = { 0, };

void jump() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0 || (i == n - 1 && j == n - 1)) continue;

			int leap = grid[i][j];
			int newx = i + leap;
			int newy = j + leap;

			if (newx < n) dp[newx][j] = dp[newx][j] + dp[i][j];
			if (newy < n) dp[i][newy] = dp[i][newy] + dp[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	dp[0][0] = 1;

	jump();
	long long ans = dp[n - 1][n - 1];
	cout << ans << "\n";;

	return 0;
}