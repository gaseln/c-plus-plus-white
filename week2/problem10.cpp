#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const std::vector<unsigned int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void NEXT(std::vector<std::string>& affairs, std::vector<int>& num_affairs, int& current_month) {
    int previous_month = current_month;
    ++current_month;
    if (current_month == 12) {
        current_month = 0;
    }
    if (months[previous_month] > months[current_month]) {
        for (int i = months[current_month]; i < months[previous_month]; ++i) {
            affairs[months[current_month] - 1] += affairs[i];
            num_affairs[months[current_month] - 1] += num_affairs[i];
            affairs[i] = "";
            num_affairs[i] = 0;
        }
    }
}


int main() {
    int current_month = 0;
    std::vector<std::string> affairs(31);
    std::vector<int> num_affairs(31);
    std::vector<std::string> out_names;
    std::vector<int> out_int;
    int N, param;
    std::cin >> N;
    std::string str;
    for (int i = 0; i < N; ++i) {
        std::cin >> str;
        if (str == "ADD") {
            std::cin >> param;
            std::cin >> str;
            affairs[param - 1] += " ";
            affairs[param - 1] += str;
            ++num_affairs[param - 1];
        }
        if (str == "NEXT") {
            NEXT(affairs, num_affairs, current_month);
        }
        if (str == "DUMP") {
            std::cin >> param;
            out_names.push_back(affairs[param - 1]);
            out_int.push_back(num_affairs[param - 1]);
        }
    }
    for (int i = 0; i < out_int.size(); ++i) {
        std::cout << out_int[i] << out_names[i] << std::endl;
    }
    return 0;
}
