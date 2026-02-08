#include <iostream>

long long fibonacciRecursive(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

long long fibonacciIterative(int n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    long long prev1 = 1;
    long long prev2 = 1;
    long long current = 0;
    
    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    int n;
    
    std::cout << "Введите номер числа Фибоначчи (n > 0): ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Номер должен быть положительным числом!" << std::endl;
        return 1;
    }
    
    std::cout << "\nРЕКУРСИВНЫЙ АЛГОРИТМ:" << std::endl;
    std::cout << "F(" << n << ") = " << fibonacciRecursive(n) << std::endl;
    
    std::cout << "\nЦИКЛИЧЕСКИЙ АЛГОРИТМ:" << std::endl;
    std::cout << "F(" << n << ") = " << fibonacciIterative(n) << std::endl;
    
    long long recResult = fibonacciRecursive(n);
    long long iterResult = fibonacciIterative(n);
    
    std::cout << "\nСравнение результатов:" << std::endl;
    if (recResult == iterResult) {
        std::cout << "Оба алгоритма дают одинаковый результат: " << recResult << std::endl;
    } else {
        std::cout << "Результаты различаются!" << std::endl;
        std::cout << "Рекурсивный: " << recResult << std::endl;
        std::cout << "Циклический: " << iterResult << std::endl;
    }
    
    std::cout << "\nПервые 15 чисел Фибоначчи:" << std::endl;
    std::cout << "n\tРекурсивно\tЦиклически" << std::endl;
    
    for (int i = 1; i <= 15; i++) {
        std::cout << i << "\t" << fibonacciRecursive(i) << "\t\t" << fibonacciIterative(i) << std::endl;
    }
    
    return 0;
}