#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort2dArray(int** arr, int rows, int cols)
{
    int maxColsIndex = cols - 1;
    for (int x = 0; x < (rows * cols); ++x) {
        for (int i = 0; i < rows; ++i) {
            int prevRow = i - 1;
            if (prevRow >= 0 && arr[prevRow][maxColsIndex] > arr[i][0]) {
                swap(&arr[prevRow][maxColsIndex], &arr[i][0]);
            }
            for (int j = 0; j < maxColsIndex; ++j) {
                int nextRow = (j + 1) > cols ? i + 1 : i;
                int nextCol = (j + 1) > cols ? 0 : j + 1;
                if (nextRow <= rows && arr[i][j] > arr[nextRow][nextCol]) {
                    swap(&arr[i][j], &arr[nextRow][nextCol]);
                }
            }
        }
    }
}

void print2dArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

double calc(double num)
{
    return sqrt(fabs(num)) + 5 * pow(num, 3);
}

void printCalculatedArray(int* arr, int size)
{
    double result;
    for (int i = 0; i < size; ++i) {
        result = calc(arr[i]);
        if (result > 400) {
            printf("[%d] Result of calculating the number %d > 400 (%lf)\n", i, arr[i], result);
        } else {
            printf("[%d] %d (%lf)\n", i, arr[i], result);
        }
    }
}

void reverseArray(int* arr, int size)
{
    int tmp[size];
    memcpy(tmp, arr, size * sizeof(int));
    for (int i = 0, j = size - 1; i < size; ++i, --j) {
        arr[i] = tmp[j];
    }
}

void algorithmTPK()
{
    const int SIZE = 11;
    int array[SIZE];

    printf("Please type %d numbers.\n", SIZE);
    for (int i = 0; i < SIZE; ++i) {
        scanf("%d", &array[i]);
    }

    reverseArray(array, SIZE);

    printCalculatedArray(array, SIZE);
}

int main(int argc, const char** argv)
{
    int example[3][3] = {{1, 9, 2}, {5, 7, 6}, {4, 3, 8}};

    const int ROWS = 3;
    const int COLS = 3;
    
    int** array = calloc(ROWS, sizeof(int*));
    for (int i = 0; i < ROWS; ++i) {
        array[i] = calloc(COLS, sizeof(int));
        for (int j = 0; j < COLS; ++j) {
            array[i][j] = example[i][j];
        }
    }

    print2dArray(array, ROWS, COLS);
    sort2dArray(array, ROWS, COLS);
    print2dArray(array, ROWS, COLS);

    algorithmTPK();

    return 0;
}
