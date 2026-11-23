#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5

int main(void) {
    int matrix[ROWS][COLS];
    srand((unsigned int)time(NULL));

    printf("Початкова матриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 41 - 20;
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    int max_sum = 0;
    int max_row = 0;
    for (int j = 0; j < COLS; j++) {
        max_sum += matrix[0][j];
    }

    for (int i = 1; i < ROWS; i++) {
        int current_sum = 0;
        for (int j = 0; j < COLS; j++) {
            current_sum += matrix[i][j];
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_row = i;
        }
    }

    printf("\nРядок з максимальною сумою: %d (сума = %d)\n", max_row, max_sum);

    for (int j = 0; j < COLS; j++) {
        if (matrix[max_row][j] != 0) {
            matrix[max_row][j] = -matrix[max_row][j];
        }
    }

    printf("\nМатриця після інвертування знаків рядка %d:\n", max_row);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}