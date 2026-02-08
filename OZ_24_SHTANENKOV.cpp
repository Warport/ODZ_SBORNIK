#include <iostream>
#include <string>

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        std::cout << " ";
    }
}

void printTreeRecursive(int level, int height) {
    if (level > height) return;
    
    printSpaces(height - level);
    
    for (int i = 0; i < 2 * level - 1; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    
    printTreeRecursive(level + 1, height);
}

void printTreeIterative(int height) {
    for (int level = 1; level <= height; level++) {
        for (int i = 0; i < height - level; i++) {
            std::cout << " ";
        }
        for (int i = 0; i < 2 * level - 1; i++) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
}

void printTrunk(int height) {
    printSpaces(height - 1);
    std::cout << "|" << std::endl;
}

void printChristmasTree(int height, bool useRecursive) {
    std::cout << "Высота ёлочки: " << height << std::endl;
    std::cout << (useRecursive ? "РЕКУРСИВНАЯ ВЕРСИЯ:" : "ЦИКЛИЧЕСКАЯ ВЕРСИЯ:") << std::endl;
    
    if (useRecursive) {
        printTreeRecursive(1, height);
    } else {
        printTreeIterative(height);
    }
    printTrunk(height);
}

void printSnowflakes() {
    std::cout << "         *     *     *" << std::endl;
    std::cout << "      *     *  *  *     *" << std::endl;
    std::cout << "         *     *     *" << std::endl;
    std::cout << "      *     *  *  *     *" << std::endl;
    std::cout << "         *     *     *" << std::endl;
}

void printStar(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = size; j > i; j--) {
            std::cout << " ";
        }
        for (int j = 1; j <= 2*i-1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void printDecorativeFrame(int width) {
    std::cout << " ";
    for (int i = 0; i < width; i++) {
        std::cout << "=";
    }
    std::cout << std::endl;
}

int main() {
    int height;
    char choice;
    
    std::cout << "ПРОГРАММА 'ВОЛШЕБНАЯ ЁЛОЧКА'" << std::endl;
    printDecorativeFrame(25);
    std::cout << std::endl;
    
    std::cout << "На какую высоту вы хотите вырастить ёлочку? (3-15): ";
    std::cin >> height;
    
    if (height < 3 || height > 15) {
        height = 5;
        std::cout << "Установлена стандартная высота: 5" << std::endl;
    }
    
    std::cout << std::endl;
    
    std::cout << "Желаете украсить ёлочку звездой на верхушке? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        std::cout << "  ☆" << std::endl;
        printStar(2);
    }
    
    
    std::cout << std::endl << "1. Рекурсивная реализация:" << std::endl;
    printChristmasTree(height, true);
    
    std::cout << std::endl << "2. Циклическая реализация:" << std::endl;
    printChristmasTree(height, false);
    
    
    std::cout << std::endl << "Ёлочка с украшениями:" << std::endl;
    for (int level = 1; level <= height; level++) {
        for (int i = 0; i < height - level; i++) {
            std::cout << " ";
        }
        for (int i = 0; i < 2 * level - 1; i++) {
            if ((level + i) % 3 == 0) {
                std::cout << "o";
            } else if ((level + i) % 5 == 0) {
                std::cout << "*";
            } else {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
    printTrunk(height);
    
    std::cout << std::endl << "Зимний пейзаж:" << std::endl;
    printSnowflakes();
    
    printDecorativeFrame(25);
    std::cout << " КРАСИВАЯ ЁЛОЧКА! " << std::endl;
    printDecorativeFrame(25);
    
    return 0;
}