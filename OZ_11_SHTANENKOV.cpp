#include <iostream>
#include <cmath>

bool isMagicSquare(int** matrix, int n) {
    bool* used = new bool[n * n + 1]();
    
    int expectedSum = n * (n * n + 1) / 2;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = matrix[i][j];
            
            if (num < 1 || num > n * n) {
                delete[] used;
                return false;
            }
            
            if (used[num]) {
                delete[] used;
                return false;
            }
            used[num] = true;
        }
    }
    
    delete[] used;
    
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != expectedSum) return false;
    }
    
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != expectedSum) return false;
    }
    
    int mainDiagSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagSum += matrix[i][i];
    }
    if (mainDiagSum != expectedSum) return false;
    
    int secondaryDiagSum = 0;
    for (int i = 0; i < n; i++) {
        secondaryDiagSum += matrix[i][n - 1 - i];
    }
    if (secondaryDiagSum != expectedSum) return false;
    
    return true;
}

int main() {
    int n;
    std::cout << "Введите размер матрицы N: ";
    std::cin >> n;
    
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
    
    std::cout << "Введите матрицу " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    
    std::cout << "\nВведенная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    if (isMagicSquare(matrix, n)) {
        int magicSum = n * (n * n + 1) / 2;
        std::cout << "\n✓ Это магический квадрат!\n";
        std::cout << "Магическая сумма: " << magicSum << "\n";
    } else {
        std::cout << "\n✗ Это НЕ магический квадрат\n";
    }
    
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}