#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

unsigned int GetNumberOfLines(std::ifstream& input) {
	unsigned int line_count = 0;
	std::string line;
	while (getline(input, line)) {
		++line_count;
	}
	return line_count;	
}

int main() {
//	std::ifstream input("E:/Projects/c-plus-plus-white/week4/input.txt");
	std::ifstream input("input.txt");
	double num;
	unsigned int line_count = GetNumberOfLines(input);
	input.clear();
	input.seekg(0, std::ios::beg);
	for (int i = 0; i < line_count; ++i) {
		input >> num;
		std::cout << std::fixed << std::setprecision(3) << num << std::endl;
	}
	return 0;
}