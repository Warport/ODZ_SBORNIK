#include <iostream>
#include <cmath>

const int N = 10;
const double EPS = 1e-9;

int main() {
    double M[N][N];
    
    std::cout << "Enter " << N << "x" << N << " matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> M[i][j];
        }
    }
    
    bool orthonormal = true;
    
    for (int i = 0; i < N && orthonormal; i++) {
        for (int j = i; j < N && orthonormal; j++) {
            double sum = 0;
            for (int k = 0; k < N; k++) {
                sum += M[i][k] * M[j][k];
            }
            
            if (i == j) {
                if (fabs(sum - 1.0) > EPS) orthonormal = false;
            } else {
                if (fabs(sum) > EPS) orthonormal = false;
            }
        }
    }
    
    if (orthonormal) {
        std::cout << "Matrix is orthonormal\n";
    } else {
        std::cout << "Matrix is NOT orthonormal\n";
    }
    
    return 0;
}