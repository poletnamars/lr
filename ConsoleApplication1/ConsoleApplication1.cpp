#include <iostream>
#include <algorithm>
#include <Windows.h>

const int ROWS = 22;
const int COLS = 2;

void sortRowDescending(int row[]) {
    std::sort(row, row + COLS, std::greater<int>());
}

void findMaxSumRows(int arr[ROWS][COLS], int& row1, int& row2) {
    int maxSum = arr[0][0] + arr[0][1];
    row1 = 0;
    row2 = 1;

    for (int i = 1; i < ROWS - 1; i++) {
        int sum = arr[i][0] + arr[i][1] + arr[i + 1][0] + arr[i + 1][1];
        if (sum > maxSum) {
            maxSum = sum;
            row1 = i;
            row2 = i + 1;
        }
    }
}

void printArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");
    int arr[ROWS][COLS];

    std::cout << "Введите элементы двумерного массива:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cin >> arr[i][j];
        }
    }

    int row1, row2;
    findMaxSumRows(arr, row1, row2);

    std::cout << "Две соседние строки с максимальной суммой: " << row1 << " и " << row2 << std::endl;

    sortRowDescending(arr[row1]);
    sortRowDescending(arr[row2]);

    std::cout << "Отсортированный массив:" << std::endl;
    printArray(arr);

    return 0;
}
// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

