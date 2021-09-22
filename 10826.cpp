#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

int N;
string fib[10001];

string calc(string x, string y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	fib[0] = "0";
	fib[1] = "1";

	for (int i = 2; i <= N; i++)
		fib[i] = calc(fib[i - 1], fib[i - 2]);

	cout << fib[N];

	return 0;
}

string calc(string x, string y) {
	string result(max(x.size(), y.size()), '0');
	bool carry = false;

	for (int i = 0; i < result.size(); i++) {
		int temp = carry;
		carry = false;

		if (i < x.size())
			temp += x[x.size() - i - 1] - '0';
		if (i < y.size())
			temp += y[y.size() - i - 1] - '0';
		if (temp >= 10) {
			carry = true;
			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	if (carry) result.insert(result.begin(), '1');

	return result;
}