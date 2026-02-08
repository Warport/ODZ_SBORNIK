#include <iostream>
#include <cmath>
#include <iomanip>

double f1(double x) {
    if (fabs(x) < 1e-10) return 1.0;
    return sin(x) / x;
}

double f2(double x) {
    return 1.0 / (1.0 + x * x);
}

double integrate(double (*func)(double),
                 double a,
                 double b,
                 int n) {
    double h = (b - a) / n;
    double sum = (func(a) + func(b)) / 2.0;
    
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += func(x);
    }
    
    return h * sum;
}

int main() {
    const int n1 = 20;
    const int n2 = 100;
    const double PI = 3.141592653589793;
    
    double c, d;
    
    std::cout << "Введите c и d (c < d): ";
    std::cin >> c >> d;
    
    if (c >= d) {
        std::cout << "Ошибка: c должно быть меньше d\n";
        return 1;
    }
    
    double I1 = integrate(f1, c, d, n1);
    double I2 = integrate(f2, 0.0, PI, n2);
    double total = I1 + I2;
    
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "\nРезультаты:\n";
    std::cout << "Первый интеграл (n=" << n1 << "): " << I1 << "\n";
    std::cout << "Второй интеграл (n=" << n2 << "): " << I2 << "\n";
    std::cout << "Сумма: " << total << "\n";
    
    return 0;
}