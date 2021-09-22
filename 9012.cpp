#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	int indicator;
	string str;

	cin >> n;

	for (int i = 0; i < n; i++)	{
		stack<int> stq;
		indicator = 0;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				stq.push(1);
			} else {
				if (stq.empty()) {
					cout << "NO" << endl;
					indicator = 1;
					break;
				} else {
					stq.pop();
				}
			}
		}

		if (indicator == 0) {
			if (!stq.empty())
				cout << "NO" << endl;
			else
				cout << "YES" << endl;
		}
	}
}