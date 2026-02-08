#include <iostream>
#include <cstdlib>
#include <ctime>

void selectionSort(int array[], int size, int& compCount, int& swapCount) {
    compCount = 0;
    swapCount = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        
        for (int j = i + 1; j < size; j++) {
            compCount++;
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }
        
        compCount++;
        if (minPos != i) {
            int tmp = array[i];
            array[i] = array[minPos];
            array[minPos] = tmp;
            swapCount++;
        }
    }
}

int main() {
    srand(time(0));
    
    int n;
    std::cout << "Введите размер массива n: ";
    std::cin >> n;
    
    const int MAX_N = 1000;
    if (n <= 0 || n > MAX_N) {
        std::cout << "Некорректный размер массива!\n";
        return 1;
    }
    
    int data[MAX_N];
    
    std::cout << "\nИсходная последовательность (" << n << " элементов):\n";
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 1000;
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";
    
    int C, M;
    selectionSort(data, n, C, M);
    
    std::cout << "Отсортированная последовательность:\n";
    for (int i = 0; i < n; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n\n";
    
    std::cout << "C(n) = " << C << " сравнений\n";
    std::cout << "M(n) = " << M << " перестановок\n";
    
    return 0;
}