#include <stdio.h>

void add(int a[20][20], int b[20][20], int r, int c);
void sub(int a[20][20], int b[20][20], int r, int c);
void mul(int a[20][20], int b[20][20], int r, int c);
void printMatrix(int mat[20][20], int r, int c);

int main () {
    int i, j, a[20][20], b[20][20], r, c, cho;
    printf("Enter the row and column: ");
    scanf("%d%d", &r, &c);

    printf("Enter the first matrix elements: ");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the second matrix elements: ");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("First matrix:\n");
    printMatrix(a, r, c);
    
    printf("Second matrix:\n");
    printMatrix(b, r, c);

    do {
        printf("\n.......MENU.......\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Subtraction\n");
        printf("3. Matrix Multiplication\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1:
                add(a, b, r, c);
                break;
            case 2:
                sub(a, b, r, c);
                break;
            case 3:
                mul(a, b, r, c);
                break;
            case 4:
                printf("Exit\n");
                return 0 ; 
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

}

void printMatrix(int mat[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void add(int a[20][20], int b[20][20], int r, int c) {
    int cSum[20][20];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cSum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Addition of matrices:\n");
    printMatrix(cSum, r, c);
}

void sub(int a[20][20], int b[20][20], int r, int c) {
    int cSub[20][20]; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cSub[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("Subtraction of matrices:\n");
    printMatrix(cSub, r, c);
}

void mul(int a[20][20], int b[20][20], int r, int c) {
    int cMul[20][20] = {0}; 
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < c; k++) {
                cMul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Multiplication of matrices:\n");
    printMatrix(cMul, r, c);
}


