#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("n/a\n");
        return 0;
    }

    // Выделение памяти под матрицы A, B и C
    int **A = (int **)malloc(N * sizeof(int *));
    int **B = (int **)malloc(N * sizeof(int *));
    int **C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Считывание матриц A и B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("n/a\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &B[i][j]) != 1) {
                printf("n/a\n");
                return 0;
            }
        }
    }

    // Умножение матриц
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Вывод матрицы C
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", C[i][j]);
            if (j != N - 1) {
                printf(" ");
            }
        }
        if (i != N - 1) {
            printf("\n");
        }
    }

    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
