/*#include <iostream>
#include <string>*/

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

/*int main() {
    std::string str;
    std::cin >> str;
    std::cout << IsPalindrom(str) << std::endl;
    return 0;
}*/
