#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int N = 9;
    int matrix[N][N];
    
    srand(time(0));
    
    std::cout << "Матрица 9x9:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 101;
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
    int center = N / 2;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == 0 || i == N-1 || j == 0 || j == N-1) {
                S1 += matrix[i][j];
            }
            
            if (i == j || i + j == N-1) {
                S2 += matrix[i][j];
            }
            
            if (abs(i-center) + abs(j-center) <= center) {
                S3 += matrix[i][j];
            }
            
            if ((i <= center && j >= i && j < N-i) || 
                (i > center && j >= N-1-i && j <= i)) {
                S4 += matrix[i][j];
            }
        }
    }
    
    std::cout << "S1 (контур) = " << S1 << "\n";
    std::cout << "S2 (диагонали) = " << S2 << "\n";
    std::cout << "S3 (ромб) = " << S3 << "\n";
    std::cout << "S4 (песочные часы) = " << S4 << "\n";
    
    return 0;
}