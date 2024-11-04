#include <stdio.h>

#define MAX 10  

void displaySparseMatrix(int rows[], int cols[], int values[], int count) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", rows[i], cols[i], values[i]);
    }
}

void addSparseMatrices(
    int rows1[], int cols1[], int values1[], int count1,
    int rows2[], int cols2[], int values2[], int count2,
    int resultRows[], int resultCols[], int resultValues[], int *resultCount
) {
    int i = 0, j = 0, k = 0;

    while (i < count1 && j < count2) {
        if (rows1[i] == rows2[j] && cols1[i] == cols2[j]) {
            resultRows[k] = rows1[i];
            resultCols[k] = cols1[i];
            resultValues[k] = values1[i] + values2[j];
            i++;
            j++;
        } else if (rows1[i] < rows2[j] || (rows1[i] == rows2[j] && cols1[i] < cols2[j])) {
            resultRows[k] = rows1[i];
            resultCols[k] = cols1[i];
            resultValues[k] = values1[i];
            i++;
        } else {
            resultRows[k] = rows2[j];
            resultCols[k] = cols2[j];
            resultValues[k] = values2[j];
            j++;
        }
        k++;
    }

    while (i < count1) {
        resultRows[k] = rows1[i];
        resultCols[k] = cols1[i];
        resultValues[k] = values1[i];
        i++;
        k++;
    }

    while (j < count2) {
        resultRows[k] = rows2[j];
        resultCols[k] = cols2[j];
        resultValues[k] = values2[j];
        j++;
        k++;
    }

    *resultCount = k;
}

int main() {
    int nonZeroCount1, nonZeroCount2;
    int rows1[MAX], cols1[MAX], values1[MAX];
    int rows2[MAX], cols2[MAX], values2[MAX];
    int resultRows[MAX], resultCols[MAX], resultValues[MAX];
    int resultCount;

    printf("Enter the number of non-zero elements in matrix 1: ");
    scanf("%d", &nonZeroCount1);

    printf("Enter row, column, and value for each non-zero element of matrix 1:\n");
    for (int i = 0; i < nonZeroCount1; i++) {
        scanf("%d %d %d", &rows1[i], &cols1[i], &values1[i]);
    }

    printf("Enter the number of non-zero elements in matrix 2: ");
    scanf("%d", &nonZeroCount2);

    printf("Enter row, column, and value for each non-zero element of matrix 2:\n");
    for (int i = 0; i < nonZeroCount2; i++) {
        scanf("%d %d %d", &rows2[i], &cols2[i], &values2[i]);
    }

    addSparseMatrices(
        rows1, cols1, values1, nonZeroCount1,
        rows2, cols2, values2, nonZeroCount2,
        resultRows, resultCols, resultValues, &resultCount
    );

    printf("\nSum of Sparse Matrix 1 and Matrix 2:\n");
    displaySparseMatrix(resultRows, resultCols, resultValues, resultCount);

    return 0;
}



/*

1d array
2d array
insertion
deletion
searching
sorting

*/