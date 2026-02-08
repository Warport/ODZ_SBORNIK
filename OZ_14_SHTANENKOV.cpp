#include <iostream>
#include <iomanip>

void inputVector(double vector[], int k, const std::string& name) {
    std::cout << "Введите вектор " << name << " (" << k << " элементов):\n";
    for (int i = 0; i < k; i++) {
        std::cout << name << "[" << i << "] = ";
        std::cin >> vector[i];
    }
}

void inputMatrix(double matrix[][10], int k, const std::string& name) {
    std::cout << "Введите матрицу " << name << " (" << k << "x" << k << "):\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << name << "[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

double dotProduct(const double v1[], const double v2[], int k) {
    double result = 0.0;
    for (int i = 0; i < k; i++) result += v1[i] * v2[i];
    return result;
}

void matrixVectorMultiply(const double matrix[][10], const double vector[], 
                         double result[], int k) {
    for (int i = 0; i < k; i++) {
        result[i] = 0.0;
        for (int j = 0; j < k; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
}

int main() {
    int k;
    
    std::cout << "Введите размерность k (2 < k < 10): ";
    std::cin >> k;
    
    double x[10], y[10];
    double A[10][10], B[10][10], C[10][10];
    double Ax[10], By[10], Cx[10];
    
    inputVector(x, k, "x");
    inputVector(y, k, "y");
    inputMatrix(A, k, "A");
    inputMatrix(B, k, "B");
    inputMatrix(C, k, "C");
    
    matrixVectorMultiply(A, x, Ax, k);
    matrixVectorMultiply(B, y, By, k);
    matrixVectorMultiply(C, x, Cx, k);
    
    double dot1 = dotProduct(Ax, By, k);
    double dot2 = dotProduct(Cx, y, k);
    double dot3 = dotProduct(x, By, k);
    
    if (abs(dot3) < 1e-10) {
        std::cout << "Ошибка: деление на ноль\n";
        return 1;
    }
    
    double result = dot1 + dot2 / dot3;
    
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nРезультат: " << result << "\n";
    
    return 0;
}