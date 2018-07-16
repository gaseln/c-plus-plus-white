#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <set>
#include <fstream>

class Date {
public:
	Date(std::string& new_date) {
		day = 0;
		month = 0;
		year = 0;
		std::vector<char> dump_check(4, '\0');
		std::istringstream str(new_date);
		std::vector<bool> flags(3);
		dump_check[0] = str.peek();
		str >> year;
		flags[0] = str.fail();
		dump_check[1] = str.peek();
		str.ignore(1);
		str >> month;
		flags[1] = str.fail();
		dump_check[2] = str.peek();
		str.ignore(1);
		str >> day;
		flags[2] = str.fail();
		str >> dump_check[3];
		if ((dump_check[3] != '\0') || (dump_check[2] != '-') || (dump_check[1] != '-') ||
			(dump_check[0] < '0') || (dump_check[0] > '9') || flags[0] || flags[1] || flags[2]) {
			//std::cout << year << "_" << month << "_" << day << dump_check[0] << "_" << dump_check[1] 
				//<< "_" << dump_check[2] << "_" << dump_check[3] << std::endl;
			throw std::runtime_error("Wrong date format: " + new_date);
		}
		if ((month < 1) || (month > 12)) {
			throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
		}
		if ((day < 1) || (day > 31)) {
			throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
		}
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int day;
	int month;
	int year;
};

std::ostream& operator<<(std::ostream& ist, const Date& date) {
	ist << std::setw(4) << std::setfill('0') << date.GetYear() << "-" << std::setw(2) << std::setfill('0') << date.GetMonth()
		<< "-" << std::setw(2) << std::setfill('0') << date.GetDay();
	return ist;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() != rhs.GetYear()) {
		return lhs.GetYear() < rhs.GetYear();
	} else if (lhs.GetMonth() != rhs.GetMonth()) {
			return lhs.GetMonth() < rhs.GetMonth(); 
	} else {
		return lhs.GetDay() < rhs.GetDay();
	}
}

class Database {
public:
	void AddEvent(const Date& date, const std::string& event) {
		database[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const std::string& event) {
		if (database[date].count(event)) {
			database[date].erase(event);
			std::cout << "Deleted successfully" << std::endl;
			return true;
		}
		else {
			std::cout << "Event not found" << std::endl;
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		int count = 0;
		if (database.count(date) != 0) {
			count = database[date].size();
			database.erase(date);
		}
		std::cout << "Deleted " << count << " events" << std::endl;
		return count;
	}

	void Find(const Date& date) const {
		try {
			auto obj = database.at(date);
			for (const auto& el : obj) {
				std::cout << el << std::endl;
			}
		}
		catch (std::out_of_range& out) {

		}
	}
  
	void Print() const {
		for (auto el : database) {
			for (auto ev : el.second) {
				std::cout << el.first << " " << ev << std::endl;
			}
		}
	}
private:
	std::map<Date, std::set<std::string>> database;
};


int main() {
  Database db;
  
  //std::ifstream stream("E:/Projects/c-plus-plus-white/week5/input.txt");

  std::string command, com_type, date, event;
  //while (getline(stream, command)) {
  while (getline(std::cin, command)) {
	  std::istringstream str(command);
	  if (command.empty()) {
		  continue;
	  }
	  str >> com_type;
	  if (com_type == "Add") {
		  try {
			  str >> date >> event;
			  db.AddEvent(Date(date), event);
		  }
		  catch (std::exception& ex) {
			  std::cout << ex.what() << std::endl;
		  }
	  }
	  else if (com_type == "Del") {
		  try {
			  str >> date;
			  if (str.eof()) {
				  db.DeleteDate(Date(date));
			  }
			  else {
				  str >> event;
				  db.DeleteEvent(Date(date), event);
			  }
		  }
		  catch (std::exception& ex) {
			  std::cout << ex.what() << std::endl;
		  }
	  }
	  else if (com_type == "Find") {
		  try {
			  str >> date;
			  db.Find(Date(date));
		  }
		  catch (std::exception& ex) {
			  std::cout << ex.what() << std::endl;
		  }
	  }
	  else if (com_type == "Print") {
		  db.Print();
	  }
	  else {
		  std::cout << "Unknown command: " << com_type << std::endl;
		  break;
	  }
  }
  return 0;
}