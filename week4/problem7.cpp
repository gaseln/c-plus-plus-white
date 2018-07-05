#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
//	std::ifstream input("E:/Projects/c-plus-plus-white/week4/input.txt");
	std::ifstream input("input.txt");
	int n, m, curr_num;
	input >> n;
	input.ignore(1);
	input >> m;
	input.ignore(1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			input >> curr_num;
			input.ignore(1);
			std::cout << std::setw(10) << curr_num;
			if (j != (m - 1)) {
				std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}
	return 0;
}