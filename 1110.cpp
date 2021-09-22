#include <iostream>

int calc(int dest, int num, int cnt);

int main() {
	int n;
	std::cin >> n;

	std::cout << calc(n, n, 1) << std::endl;

	return 0;
}

int calc(int dest, int num, int cnt) {
	int tens, ones;
	
	tens = num % 10;
	ones = ((num / 10) + (num % 10)) % 10;


	num = tens * 10 + ones;

	if (dest == num) return cnt;
	else return calc(dest, num, ++cnt);
}