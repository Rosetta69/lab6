#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main() {
    // Ініціалізуємо генератор псевдовипадкових чисел
    srand(time(NULL));
    
    // Заповнюємо матрицю випадковими дійсними числами
    double matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = ((double) rand() / RAND_MAX) * 200 - 100;
        }
    }

    // Виводимо початкову матрицю
    printf("Початкова матриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%8.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Знаходимо рядки з максимальною та мінімальною сумою елементів
    int max_row = 0;
    double max_sum = 0;
    int min_row = 0;
    double min_sum = 0;
    for (int i = 0; i < ROWS; i++) {
        double sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
        if (sum > max_sum) {
            max_row = i;
            max_sum = sum;
        }
        if (i == 0 || sum < min_sum) {
            min_row = i;
            min_sum = sum;
        }
    }
    
    // Переставляємо рядки
    if (max_row != min_row) {
        double temp[COLS];
        for (int j = 0; j < COLS; j++) {
            temp[j] = matrix[max_row][j];
            matrix[max_row][j] = matrix[min_row][j];
            matrix[min_row][j] = temp[j];
        }
        printf("Результат:\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%8.2lf ", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Рядки з найбільшою та найменшою сумою елементів збігаються.\n");
    }
    
    return 0;
}
