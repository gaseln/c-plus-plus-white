//#include <iostream>

int Factorial(int n) {
    if (n < 1) {
        return 1;
    }
    int res  = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

/*int main() {
    int n;
    std::cin >> n;
    std::cout << Factorial(n) << std::endl;
    return 0;
}*/

