#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	w = w - x;
	h = h - y;
	int min = (x < y) ? x : y;
	min = (((w < h) ? w : h) < min) ? ((w < h) ? w : h) : min;

	cout << min << endl;
}