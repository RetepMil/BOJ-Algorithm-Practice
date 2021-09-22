#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int T;

char dict[10][6] = { "ZERO", "TWO", "FOUR", "SIX", "EIGHT", "THREE", "FIVE", "SEVEN", "NINE", "ONE" },
alphabetOrder[] = "ZWUXGHFVIE";
int inNumOrder[] = { 0, 2, 4, 6, 8, 3, 5, 7, 9, 1 };

multiset<int> ans;

void countAlphabet(int * alphabetFreq, int idx) {
	ans.insert(inNumOrder[idx]);
	for (char alphabet : dict[idx])
		alphabetFreq[alphabet - 'A']--;
}

void solve(int caseNum) {
	int alphabetFreq[26] = {};
	string S;
	cin >> S;

	for (char alphabet : S)
		alphabetFreq[alphabet - 'A']++;

	for (int i = 0; i < 10; i++)
		while (alphabetFreq[alphabetOrder[i] - 'A'])
			countAlphabet(alphabetFreq, i);

	cout << "Case #" << caseNum + 1 << ": ";
	for (auto i : ans) cout << i;
	cout << "\n";

	ans.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
		solve(i);

	return 0;
}