#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> poslist;
	vector<int> neglist;
	int n;
	cin >> n;

	bool zero = false;
	int ones = 0;;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num < 0)
			neglist.push_back(num);
		else if (num > 1)
			poslist.push_back(num);
		else if (num == 1)
			ones++;
		else
			zero = true;

	}
	sort(poslist.begin(), poslist.end());
	sort(neglist.begin(), neglist.end());

	long sum = 0;

	//add all poslist elements except 1
	if (poslist.size() > 1)
		for (int i = poslist.size() - 1; i > 0; i -= 2) {
			sum += (poslist[i] * poslist[i - 1]);
		}
	if (poslist.size() % 2 != 0)
		sum += poslist[0];

	//add all neglist elements
	if (neglist.size() > 0) {
		if (neglist.size() != 1)
			for (int i = 0; i < neglist.size() - 1; i += 2) {
				sum += (neglist[i] * neglist[i + 1]);
			}

		//when neglist size is odd
		if (neglist.size() % 2 == 1) {
			if (!zero)
				sum += neglist[neglist.size() - 1];
		}
	}
	sum += ones;

	cout << sum;

	return 0;
}