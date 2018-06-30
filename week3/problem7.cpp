#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
	string name;  
	for (const auto& item : names) {
		if (item.first <= year) {
			name = item.second;
		}
		else {
			break;
		}
	}
	return name;
}

string FindWholeNameHistoryByYear(const map<int, string>& names, int year) {
	string name; 
	vector<string> my_names;
	string out;


	for (const auto& item : names) {
		if ((item.first <= year) && (name != item.second)) {
			my_names.push_back(item.second);
			name = item.second;
		}
		else {
			break;
		}
	}
	reverse(my_names.begin(), my_names.end());
	if (my_names.size() > 0) {
		out = my_names[0];
		if (my_names.size() > 1) {
			out += " (";
			for (int i = 1; i < my_names.size(); ++i) {
				out += my_names[i] + ", ";
			}
			out = out.substr(0, out.size() - 2);
			out += ")";
		}
	}
	return out;
}

class Person {
public:
	Person(std::string first_name, std::string last_name, int year) {
		first_names[year] = first_name;
		last_names[year] = last_name;
		year_of_birth = year;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year >= year_of_birth) {
			first_names[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= year_of_birth) {
			last_names[year] = last_name;
		}
	}
	string GetFullName(int year) const {
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);
		if (year < year_of_birth) {
			return "No person";
		}
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";
		}
		else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) const {
		const string first_name = FindWholeNameHistoryByYear(first_names, year);
		const string last_name = FindWholeNameHistoryByYear(last_names, year);
		if (year < year_of_birth) {
			return "No person";
		}
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";
		}
		else {
			return first_name + " " + last_name;
		}
	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
	int year_of_birth;
};

