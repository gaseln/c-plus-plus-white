#include <iostream>
#include <vector>

int main() {
	int N;
	std::vector<int> binary_number(0);
	std::cin >> N;
	while (N > 0) {
		binary_number.push_back(N % 2);
		N /= 2;
	}
	for (int i = binary_number.size() - 1; i >= 0; --i) {
		std::cout << binary_number[i];
	}
	return 0;
}
