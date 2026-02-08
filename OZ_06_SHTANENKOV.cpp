#include <iostream>
#include <cmath>

int main() {
    double N, D, eps;
    
    std::cout << "Введите делимое N: ";
    std::cin >> N;
    
    std::cout << "Введите делитель D (D ≠ 0): ";
    std::cin >> D;
    
    if (D == 0) {
        std::cout << "Ошибка: делитель не может быть равен 0!\n";
        return 1;
    }
    
    std::cout << "Введите точность eps (eps > 0): ";
    std::cin >> eps;
    
    if (eps <= 0) {
        std::cout << "Ошибка: точность должна быть больше 0!\n";
        return 1;
    }
    
    double x;
    if (std::abs(D) < 1.0) {
        x = (D > 0) ? 1.0 : -1.0;
    } else {
        x = 1.0 / (2.0 * D);
    }
    
    double x_prev;
    do {
        x_prev = x;
        x = x * (2.0 - D * x);
    } while (std::abs(x - x_prev) >= eps);
    
    double result = N * x;
    std::cout << "\nРезультат: " << N << " / " << D << " = " << result << "\n";
    
    return 0;
}