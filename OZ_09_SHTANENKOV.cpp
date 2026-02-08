#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int a, b, c;
    
    std::cout << "Введите размерности матриц:\n";
    std::cout << "Строки A: ";
    std::cin >> a;
    std::cout << "Столбцы A / Строки B: ";
    std::cin >> b;
    std::cout << "Столбцы B: ";
    std::cin >> c;
    
    int M1[a][b], M2[b][c], R[a][c];
    
    srand(time(0));
    
    std::cout << "\nМатрица M1 (" << a << "x" << b << "):\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            M1[i][j] = rand() % 100;
            std::cout << M1[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    std::cout << "\nМатрица M2 (" << b << "x" << c << "):\n";
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < c; j++) {
            M2[i][j] = rand() % 100;
            std::cout << M2[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            R[i][j] = 0;
            for (int k = 0; k < b; k++) {
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
    
    std::cout << "\nРезультат R = M1 * M2 (" << a << "x" << c << "):\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            std::cout << R[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    return 0;
}