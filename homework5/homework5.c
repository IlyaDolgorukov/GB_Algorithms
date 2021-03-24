#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillArray(int* array, int size, int max)
{
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        *(array + i) = rand() % max;
    }
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; ++i) {
        printf("%3d", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int getMedian(int *arr, int first, int last) {
    int middle = arr[(first + last) / 2];
    int min = arr[first] > arr[middle] ? arr[middle] : arr[first];
    int max = arr[first] > arr[middle] ? arr[first] : arr[middle];
    int result = arr[last] < min ? min : (arr[last] > max ? max : arr[last]);

    return result == arr[first] ? first : (result == arr[middle] ? middle : last);
}

void sortByInsert(int *array, int first, int last)
{
    int temp, pos;
    for (int i = first + 1; i <= last; i++) {
        temp = array[i];
        pos = i - 1;
        while (pos >= first && array[pos] > temp) {
            array[pos + 1] = array[pos];
            pos = pos - 1;
        }
        array[pos + 1] = temp;
    }
}

void improvedQuickSort(int* arr, int first, int last)
{
    if (last - first > 10) {
        int median = getMedian(arr, first, last);
        swap(&arr[median], &arr[(first + last) / 2]);
        int i = first;
        int j = last;
        int x = arr[(first + last) / 2];
        do {
            while (arr[i] < x) i++;
            while (arr[j] > x) j--;
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        } while (i <= j);

        improvedQuickSort(arr, i, last);
        improvedQuickSort(arr, first, j);
    } else {
        sortByInsert(arr, first, last);
        return;
    }
}


int main(int argc, const char** argv)
{
    const int SIZE = 20;

    int arr1[SIZE];
    fillArray(arr1, SIZE, 100);
    printArray(arr1, SIZE);
    improvedQuickSort(arr1, 0, SIZE - 1);
    printArray(arr1, SIZE);
    printf("\n");

    return 0;
}