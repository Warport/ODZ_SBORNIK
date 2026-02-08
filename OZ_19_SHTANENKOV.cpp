#include <iostream>
#include <vector>
#include <random>

struct SortResult {
    int comparisons;
    int swaps;
};

SortResult binaryInsertionSort(std::vector<int>& arr) {
    SortResult result;
    result.comparisons = 0;
    result.swaps = 0;
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;
        
        while (left <= right) {
            result.comparisons++;
            int mid = (left + right) / 2;
            if (arr[mid] < key) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int insertPos = left;
        for (int j = i; j > insertPos; j--) {
            arr[j] = arr[j - 1];
            result.swaps++;
        }
        
        arr[insertPos] = key;
    }
    
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
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным!" << std::endl;
        return 1;
    }
    
    std::vector<int> arr = generateRandomArray(n);
    
    printArray(arr, "Исходный массив");
    
    SortResult result = binaryInsertionSort(arr);
    
    printArray(arr, "Отсортированный массив");
    
    std::cout << "Количество сравнений C(n): " << result.comparisons << std::endl;
    std::cout << "Количество перестановок M(n): " << result.swaps << std::endl;
    
    return 0;
}