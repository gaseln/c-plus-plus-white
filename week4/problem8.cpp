#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

struct Student {
	std::string name, surname;
	int day, month, year;
	Student(std::string new_name, std::string new_surname, int new_day, int new_month, int new_year) {
		name = new_name;
		surname = new_surname;
		day = new_day;
		month = new_month;
		year = new_year;
	}
};

int main() {
	int N, M;
	std::string name, surname, curr_str, command;
//	std::ofstream output("input.txt");
//	std::ofstream output("E:/Projects/c-plus-plus-white/week4/input.txt");
	int day, month, year, student_num;
	std::cin >> N;
	std::vector<Student> students;
	for (int i = 0; i < N; ++i) {
		std::cin >> name >> surname >> day >> month >> year;
		students.push_back(Student(name, surname, day, month, year));
	}
	std::cin >> M;
	std::cin.ignore(1);
	for (int i = 0; i < M; ++i) {
		std::cin >> command >> student_num;
		if ((command == "name") && (student_num > 0) && (student_num <= students.size())) {
			std::cout << students[student_num - 1].name << " " << students[student_num - 1].surname <<
				std::endl;
		}
		else if ((command == "date") && (student_num > 0) && (student_num <= students.size())) {
			std::cout << students[student_num - 1].day << "." <<
				students[student_num - 1].month << "." <<
				students[student_num - 1].year << std::endl;
		}
		else {
			std::cout << "bad request" << std::endl;
		}
	}
//	output.close();
//	std::ifstream input("input.txt");
//	std::ifstream input("E:/Projects/c-plus-plus-white/week4/input.txt");
//	while (getline(input, curr_str)) {
//		std::cout << curr_str << std::endl;
//	}
	return 0;
}