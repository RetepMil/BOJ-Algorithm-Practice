#include <iostream>

using namespace std;
int main() {
	int n, j, cnt = 0;
	string word;
	int cache[26];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> word;
		fill_n(cache, 26, 0);

		cache[word[0] - 'a'] = 1;
		for (j = 1; j < word.length(); j++) {
			if (word[j] != word[j-1]) {
				if (cache[word[j] - 'a'] == 0)
					cache[word[j] - 'a']++;
				else
					break;
			}
		}
		if (j == word.length())
			cnt++;
	}
	cout << cnt;

	return 0;
}