#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

vector<int> input;
int dp[5][5][100000];

int calcEnergy(int from, int to) {
	if (from == to) return 1;
	if (from == 0) return 2;
	int foo = from - to;
	if (foo == -2 || foo == 2) return 4;
	else return 3;
}

int solve(int left, int right, int seq) {
	if (seq == input.size()) return 0;
	int& reference = dp[left][right][seq];
	int changeto = input[seq];
	if (reference != 0) return reference;
	return reference = min(calcEnergy(left, changeto) + solve(changeto, right, seq + 1),
		calcEnergy(right, changeto) + solve(left, changeto, seq + 1));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		int num;
		cin >> num;
		if (num == 0) break;
		input.push_back(num);
	} 

	cout << solve(0, 0, 0) << "\n";

	return 0;
}