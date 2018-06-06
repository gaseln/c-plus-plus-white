/*#include <iostream>
#include <string>
#include <vector>*/

bool IsPalindrom(std::string str) {
    int n = str.size();
    //std::cout << n <<std::endl;
    for (int i = 0; i < n/2; ++i) {
        if (str[i] != str[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) {
    std::vector<std::string> res = {};
    for (auto word: words) {
        if ((IsPalindrom(word)) && (word.size() >= minLength)) {
            res.push_back(word);
        }
    }
    return res;
}

/*int main() {
    std::vector<std::string> str = {"weew", "bro", "code"};
//    std::cin >> str;
//    std::cout << PalindromFilter(str, 5) << std::endl;
    for (auto c: PalindromFilter(str, 4)) {
        std::cout << c << std::endl;
    }
    return 0;
}*/
