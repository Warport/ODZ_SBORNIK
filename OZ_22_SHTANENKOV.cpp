#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct SortResult {
    long long comparisons;
    long long moves;
};

SortResult bubbleSort(vector<int>& arr) {
    long long comparisons = 0;
    long long moves = 0;
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                moves++;
            }
        }
    }
    
    return {comparisons, moves};
}

SortResult selectionSort(vector<int>& arr) {
    long long comparisons = 0;
    long long moves = 0;
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            moves++;
        }
    }
    
    return {comparisons, moves};
}

SortResult insertionSort(vector<int>& arr) {
    long long comparisons = 0;
    long long moves = 0;
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        comparisons++;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            moves++;
            j--;
        }
        arr[j + 1] = key;
        if (j + 1 != i) moves++;
    }
    
    return {comparisons, moves};
}

int partition(vector<int>& arr, int low, int high, long long& comparisons, long long& moves) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] <= pivot) {
            i++;
            if (i != j) {
                swap(arr[i], arr[j]);
                moves++;
            }
        }
    }
    
    if (i + 1 != high) {
        swap(arr[i + 1], arr[high]);
        moves++;
    }
    return i + 1;
}

void quickSortRecursive(vector<int>& arr, int low, int high, long long& comparisons, long long& moves) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, moves);
        quickSortRecursive(arr, low, pi - 1, comparisons, moves);
        quickSortRecursive(arr, pi + 1, high, comparisons, moves);
    }
}

SortResult quickSort(vector<int>& arr) {
    long long comparisons = 0;
    long long moves = 0;
    int n = arr.size();
    
    quickSortRecursive(arr, 0, n - 1, comparisons, moves);
    
    return {comparisons, moves};
}

void mergeInPlace(vector<int>& arr, int left, int mid, int right, long long& comparisons, long long& moves) {
    int i = left;
    int j = mid + 1;
    
    while (i <= mid && j <= right) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            i++;
        } else {
            int value = arr[j];
            int index = j;
            
            while (index != i) {
                arr[index] = arr[index - 1];
                moves++;
                index--;
            }
            arr[i] = value;
            moves++;
            
            i++;
            mid++;
            j++;
        }
    }
}

void mergeSortRecursive(vector<int>& arr, int left, int right, long long& comparisons, long long& moves) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(arr, left, mid, comparisons, moves);
        mergeSortRecursive(arr, mid + 1, right, comparisons, moves);
        mergeInPlace(arr, left, mid, right, comparisons, moves);
    }
}

SortResult mergeSort(vector<int>& arr) {
    long long comparisons = 0;
    long long moves = 0;
    int n = arr.size();
    
    mergeSortRecursive(arr, 0, n - 1, comparisons, moves);
    
    return {comparisons, moves};
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (size_t i = 0; i < min(arr.size(), (size_t)10); i++) {
        cout << arr[i] << " ";
    }
    if (arr.size() > 10) {
        cout << "... (всего " << arr.size() << " элементов)";
    }
    cout << endl;
}

void printSortResult(const SortResult& result, const string& algorithmName) {
    cout << "=== " << algorithmName << " ===" << endl;
    cout << "C(n) сравнений: " << result.comparisons << endl;
    cout << "M(n) перестановок: " << result.moves << endl;
    cout << endl;
}

int main() {
    const int SIZE = 20;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    
    vector<int> originalArray(SIZE);
    for (int i = 0; i < SIZE; i++) {
        originalArray[i] = dis(gen);
    }
    
    cout << "Исходный массив:" << endl;
    printArray(originalArray, "Original");
    cout << endl;
    
    cout << "СРАВНЕНИЕ ЭФФЕКТИВНОСТИ АЛГОРИТМОВ СОРТИРОВКИ" << endl;
    cout << "=============================================" << endl << endl;
    
    vector<vector<int>> testArrays = {
        originalArray,
        originalArray,
        originalArray,
        originalArray,
        originalArray
    };
    
    vector<SortResult> results;
    vector<string> algorithmNames = {
        "Сортировка пузырьком (Bubble Sort)",
        "Сортировка выбором (Selection Sort)",
        "Сортировка вставками (Insertion Sort)",
        "Быстрая сортировка (Quick Sort)",
        "Сортировка слиянием (Merge Sort) - in-place"
    };
    
    for (int i = 0; i < 5; i++) {
        vector<int> arr = testArrays[i];
        SortResult result;
        
        switch(i) {
            case 0: result = bubbleSort(arr); break;
            case 1: result = selectionSort(arr); break;
            case 2: result = insertionSort(arr); break;
            case 3: result = quickSort(arr); break;
            case 4: result = mergeSort(arr); break;
        }
        
        results.push_back(result);
        printSortResult(result, algorithmNames[i]);
    }
    
    bool allSortedCorrectly = true;
    vector<int> sortedReference = originalArray;
    sort(sortedReference.begin(), sortedReference.end());
    
    for (int i = 0; i < 5; i++) {
        vector<int> arr = testArrays[i];
        if (arr != sortedReference) {
            allSortedCorrectly = false;
            break;
        }
    }
    
    cout << "Проверка корректности сортировки:" << endl;
    if (allSortedCorrectly) {
        cout << "✓ Все алгоритмы отсортировали массив правильно" << endl;
        cout << "Отсортированный массив: ";
        for (size_t i = 0; i < min(sortedReference.size(), (size_t)10); i++) {
            cout << sortedReference[i] << " ";
        }
        if (sortedReference.size() > 10) {
            cout << "...";
        }
        cout << endl;
    } else {
        cout << "✗ Ошибка: не все алгоритмы отсортировали массив правильно!" << endl;
    }
    
    return 0;
}