#include <iostream>
#include <map>
#include <string>

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const std::string& last_name) {
		last_names[year] = last_name;
	}
	std::string GetFullName(int year) {
		if (first_names.empty() && last_names.empty()) {
			return "Incognito";
		}
		std::map<int, std::string>::iterator first, last;
		first = first_names.upper_bound(year);
		last = last_names.upper_bound(year);
		if ((first != first_names.begin()) &&
			(last != last_names.begin())) {
			first--;
			last--;
			return first->second + " " + last->second;
		}
		else if ((first == first_names.begin()) &&
			(last == last_names.begin())) {
			return "Incognito";
		}
		else if (first == first_names.begin()) {
			last--;
			return last->second + " with unknown first name";
		}
		else {
			first--;
			return first->second + " with unknown last name";
		}
	}
private:
	std::map<int, std::string> first_names;
	std::map<int, std::string> last_names;
};

/*
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	return 0;
} */