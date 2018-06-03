#include <iostream>

int main() {
	int A, B, C;
	std::cin >> A >> B;
	if (B != 0) {
		C = A / B;
		std::cout << C << std::endl;
	}
	else {
		std::cout << "Impossible" << std::endl;
	}
}
