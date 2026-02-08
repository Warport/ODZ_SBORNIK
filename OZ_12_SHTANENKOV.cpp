#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int rows = 10;
    const int cols = 15;
    int v[rows][cols];
    
    srand(time(0));
    
    std::cout << "Матрица 10x15:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            v[i][j] = rand() % 100;
            std::cout << v[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    std::cout << "\nСедловые точки:\n";
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = v[i][j];
            
            bool minInRow = true;
            bool maxInRow = true;
            bool minInCol = true;
            bool maxInCol = true;
            
            for (int k = 0; k < cols; k++) {
                if (k != j) {
                    if (v[i][k] < current) minInRow = false;
                    if (v[i][k] > current) maxInRow = false;
                }
            }
            
            for (int k = 0; k < rows; k++) {
                if (k != i) {
                    if (v[k][j] < current) minInCol = false;
                    if (v[k][j] > current) maxInCol = false;
                }
            }
            
            if ((minInRow && maxInCol) || (maxInRow && minInCol)) {
                std::cout << "(" << i << ", " << j << ") = " << current << "\n";
            }
        }
    }
    
    return 0;
}