#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

struct SortResult {
    std::vector<int> sortedArray;
    int comparisons;
    int swaps;
};

SortResult shakerSort(std::vector<int> arr) {
    SortResult result;
    result.sortedArray = arr;
    result.comparisons = 0;
    result.swaps = 0;
    
    int n = result.sortedArray.size();
    if (n <= 1) return result;
    
    int left = 0;
    int right = n - 1;
    bool swapped;
    
    while (left < right) {
        swapped = false;
        
        for (int i = left; i < right; i++) {
            result.comparisons++;
            if (result.sortedArray[i] > result.sortedArray[i + 1]) {
                std::swap(result.sortedArray[i], result.sortedArray[i + 1]);
                result.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
        right--;
        
        swapped = false;
        
        for (int i = right; i > left; i--) {
            result.comparisons++;
            if (result.sortedArray[i] < result.sortedArray[i - 1]) {
                std::swap(result.sortedArray[i], result.sortedArray[i - 1]);
                result.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
        left++;
    }
    
    return result;
}

std::vector<int> generateRandomArray(int n, int minVal = 1, int maxVal = 100) {
    std::vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
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
    srand(time(nullptr));
    
    int n;
    std::cout << "Введите размер массива: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Размер массива должен быть положительным!" << std::endl;
        return 1;
    }
    
    std::vector<int> arr = generateRandomArray(n);
    
    printArray(arr, "Исходный массив");
    
    SortResult result = shakerSort(arr);
    
    printArray(result.sortedArray, "Отсортированный массив");
    
    std::cout << "Количество сравнений C(n): " << result.comparisons << std::endl;
    std::cout << "Количество перестановок M(n): " << result.swaps << std::endl;
    
    return 0;
}