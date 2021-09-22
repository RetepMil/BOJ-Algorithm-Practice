#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int D;
vector<int> adj[8];
ll dp[100001][8];

void setEnvironment() {
	for (int i = 0; i < 8; i++) {
		int left = i - 1;
		int right = i + 1;

		if (left < 0)
			left = 7;
		if (right > 7)
			right = 0;

		adj[i].push_back(left);
		adj[i].push_back(right);
	}

	adj[1].push_back(7);
	adj[1].push_back(6);
	adj[2].push_back(5);
	adj[2].push_back(6);
	adj[5].push_back(2);
	adj[6].push_back(2);
	adj[6].push_back(1);
	adj[7].push_back(1);

	for (int i = 0; i < 100001; i++)
		for (int j = 0; j < 8; j++)
			dp[i][j] = -1;
}

int solve(int currLoc, int pastTime) {
	if (pastTime == D) return (currLoc == 0) ? 1 : 0;
	ll& ret = dp[pastTime][currLoc];

	if (ret != -1) return ret;
	ret = 0;
	for (int adjLoc : adj[currLoc]) {
		ret += solve(adjLoc, pastTime + 1);
	}
	ret %= 1000000007;

	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	setEnvironment();
	cin >> D;

	cout << solve(0, 0) << "\n";

	return 0;
}