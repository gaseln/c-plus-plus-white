#include <iostream>
#include <fstream>
#include <string>

int main() {
//	std::ifstream input("E:/Projects/c-plus-plus-white/week4/input.txt");
	std::ifstream input("input.txt");
	std::string line;
	if (input.is_open()) {
		while (getline(input, line)) {
			std::cout << line << std::endl;
		}
	}
	return 0;
}