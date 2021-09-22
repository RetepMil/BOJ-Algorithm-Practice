#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
 bool comparator(string a, string b) {
	 if (a.length() == b.length())
		 return a < b;
	 else
		 return a.length() < b.length();
}

 /*
void quick_sort(vector<string> &words, int i, int j) {
	if (i == j)
		return;
	vector<string> buffer(i - j + 1);
	int left = -1;
	int right = buffer.size();
	int pos = i + 1;

	while (pos != buffer.size() - 1) {
		if (comparator(words[i], words[pos]))
			buffer[++left] = words[pos];
		else
			buffer[--right] = words[pos];
		pos++;
	}
	buffer[left + 1] = words[i];
	copy(buffer.begin(), buffer.end(), words.begin());

	quick_sort(words, i, left);
	quick_sort(words, right, j);
}
 */


int main() {
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;
	vector<string> words;
	string input;

	while (n--) {
		cin >> input;
		words.push_back(input);
	}

	sort(words.begin(), words.end(), comparator);

	vector<string> ans;
	ans.push_back(words.front());
	for (int i = 1; i < words.size(); i++) {
		if (ans.back() != words.at(i))
			ans.push_back(words.at(i));
	}

	for (string i : ans) cout << i << "\n";

	return 0;
}