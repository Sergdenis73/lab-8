#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    system("chcp 65001");
    int A[ROWS][COLS] = {
        {5, 8, 3, -4},
        {-5, 6, -4, 8},
        {9, -3, 11, -12}
    };

    int B[ROWS][COLS] = {
        {-12, 2, -3, 4},
        {8, -6, 7, -8},
        {-9, 10, -1, 12}
    };

    int C[ROWS][COLS];
    
    // Складання матриць A і B -> C
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Вивід результату складання
    printf("Матриця C (результат складання A + B):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    // Пошук найбільшого серед від’ємних елементів
    int max_negative;
    int found = 0;
    int max_row = -1, max_col = -1;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (C[i][j] < 0) {
                if (!found || C[i][j] > max_negative) {
                    max_negative = C[i][j];
                    max_row = i;
                    max_col = j;
                    found = 1;
                }
            }
        }
    }

    if (found) {
        printf("\nНайбільший серед від’ємних елементів: %d\n", max_negative);
        printf("Його індекси: рядок = %d, стовпець = %d\n", max_row, max_col);
    } else {
        printf("\nВ матриці C немає від’ємних елементів.\n");
    }

    return 0;
}
