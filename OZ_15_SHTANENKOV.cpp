#include <iostream>
#include <cmath>

const int MAX_SIZE = 10;

void inputMatrix(double matrix[][MAX_SIZE], int n, const std::string& name) {
    std::cout << "Введите матрицу " << name << " (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << name << "[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "\n";
}

void printMatrix(double matrix[][MAX_SIZE], int n, const std::string& name) {
    std::cout << "Матрица " << name << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

double matrixNorm(double matrix[][MAX_SIZE], int n) {
    double maxAbs = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double absVal = std::abs(matrix[i][j]);
            if (absVal > maxAbs) {
                maxAbs = absVal;
            }
        }
    }
    return maxAbs;
}

int findMinIndex(double norms[], int count) {
    int minIndex = 0;
    for (int i = 1; i < count; i++) {
        if (norms[i] < norms[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n;
    
    std::cout << "Введите размер матриц n (2 < n < 10): ";
    std::cin >> n;
    
    double A[MAX_SIZE][MAX_SIZE];
    double B[MAX_SIZE][MAX_SIZE];
    double C[MAX_SIZE][MAX_SIZE];
    
    inputMatrix(A, n, "A");
    inputMatrix(B, n, "B");
    inputMatrix(C, n, "C");
    
    std::cout << "\n=== Введенные матрицы ===\n\n";
    printMatrix(A, n, "A");
    printMatrix(B, n, "B");
    printMatrix(C, n, "C");
    
    double normA = matrixNorm(A, n);
    double normB = matrixNorm(B, n);
    double normC = matrixNorm(C, n);
    
    std::cout << "Норма матрицы A: " << normA << "\n";
    std::cout << "Норма матрицы B: " << normB << "\n";
    std::cout << "Норма матрицы C: " << normC << "\n\n";
    
    double norms[3] = {normA, normB, normC};
    const char* names[3] = {"A", "B", "C"};
    
    int minIndex = findMinIndex(norms, 3);
    
    std::cout << "Матрица с наименьшей нормой: " << names[minIndex] 
              << " (норма = " << norms[minIndex] << ")\n";
    
    return 0;
}
