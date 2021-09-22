#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int N, M;
string comb[101][101];

string addBigNum(string s1, string s2) {
	int temp = 0;
	string result;

	while (!s1.empty() || !s2.empty() || temp) {
		if (!s1.empty()) {
			temp += s1.back() - '0';
			s1.pop_back();
		}
		if (!s2.empty()) {
			temp += s2.back() - '0';
			s2.pop_back();
		}
		result.push_back((temp % 10) + '0');
		temp /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string combination(int n, int r) {
	if (n == r || r == 0) return "1";
	if (comb[n][r] != "") return comb[n][r];
	comb[n][r] = addBigNum(combination(n - 1, r - 1), combination(n - 1, r));

	return comb[n][r];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	cout << combination(N, M);

	return 0;
}