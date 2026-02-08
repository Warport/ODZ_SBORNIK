#include <iostream>
#include <vector>
#include <random>

struct SortResult {
    std::vector<int> sortedArray;
    int comparisons;
    int swaps;
};

SortResult insertionSort(std::vector<int> arr) {
    SortResult result;
    result.comparisons = 0;
    result.swaps = 0;
    
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            result.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                result.swaps++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        if (j + 1 != i) {
            result.swaps++;
        }
    }
    
    result.sortedArray = arr;
    return result;
}

std::vector<int> generateRandomArray(int n, int minVal = 1, int maxVal = 100) {
    std::vector<int> arr(n);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(minVal, maxVal);
    
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
    return arr;
}

void printArray(const std::vector<int>& arr, const std::string& message = "") {
    if (!message.empty()) {
        std::cout << message << ": ";
    }
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    
    std::vector<int> arr = generateRandomArray(n);
    
    printArray(arr, "Исходный массив");
    
    SortResult result = insertionSort(arr);
    
    printArray(result.sortedArray, "Отсортированный массив");
    
    std::cout << "Количество сравнений C(n): " << result.comparisons << std::endl;
    std::cout << "Количество перестановок M(n): " << result.swaps << std::endl;
    
    return 0;
}