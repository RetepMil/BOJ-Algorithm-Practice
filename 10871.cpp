#include <iostream>

int main() {
	int n; 
	int reference;

	std::cin >> n >> reference;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	for (int j = 0; j < n; j++) {
		if (arr[j] < reference)
			std::cout << arr[j] << " ";
	}

	return 0;
}