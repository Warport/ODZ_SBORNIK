#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int N = 7;
    double m[N][N];
    
    srand(time(0));
    
    std::cout << "Матрица:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = (rand() % 2001 - 1000) / 1000.0;
            std::cout << m[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    double maxVal = m[0][0], minVal = m[0][0];
    int maxR = 0, minC = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
                maxR = i;
            }
            if (m[i][j] < minVal) {
                minVal = m[i][j];
                minC = j;
            }
        }
    }
    
    double result = 0;
    for (int i = 0; i < N; i++) {
        result += m[maxR][i] * m[i][minC];
    }
    
    std::cout << "\nСкалярное произведение = " << result << "\n";
    
    return 0;
}