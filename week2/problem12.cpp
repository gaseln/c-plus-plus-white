#include <iostream>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::string> capitals;
std::vector<std::string> out;

void ChangeCapital(std::string& country, std::string& new_capital) {
    if (capitals.count(country) == 0) {
        out.push_back("Introduce new country " + country + " with capital " + new_capital);
        capitals[country] = new_capital;
    } else {
        if (capitals[country] == new_capital) {
            out.push_back("Country " + country + " hasn't changed its capital");
        } else {
            out.push_back("Country " + country + " has changed its capital from " + capitals[country] + " to " + new_capital);
            capitals[country] = new_capital;
        }
    }
}

void Rename(std::string& old_country_name, std::string& new_country_name) {
    if ((old_country_name == new_country_name) || (capitals.count(old_country_name) == 0) ||
            (capitals.count(new_country_name) == 1)) {
        out.push_back("Incorrect rename, skip");
    } else {
        out.push_back("Country " + old_country_name + " with capital " + capitals[old_country_name] +
                      " has been renamed to " + new_country_name);
        capitals[new_country_name] = capitals[old_country_name];
        capitals.erase(old_country_name);
    }
}

void About(std::string& country) {
    if (capitals.count(country) == 0) {
        out.push_back("Country " + country + " doesn't exist");
    } else {
        out.push_back("Country " + country + " has capital " + capitals[country]);
    }
}

void Dump() {
    if (capitals.empty()) {
        out.push_back("There are no countries in the world");
    } else {
        std::string new_push;
        for (const auto& item: capitals) {
            new_push += item.first + "/" + item.second + " ";
        }
        out.push_back(new_push);
    }
}

int main() {
    int Q, i;
    std::cin >> Q;
    std::string command, str1, str2;
    for (i = 0; i < Q; ++i) {
        std::cin >> command;
        if (command == "CHANGE_CAPITAL") {
            std::cin >> str1 >> str2;
            ChangeCapital(str1, str2);
        }
        if (command == "RENAME") {
            std::cin >> str1 >> str2;
            Rename(str1, str2);
        }
        if (command == "ABOUT") {
            std::cin >> str1;
            About(str1);
        }
        if (command == "DUMP") {
            Dump();
        }
    }
    for (i = 0; i < out.size(); ++i) {
        std::cout << out[i] << std::endl;
    }
    return 0;
}
