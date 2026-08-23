#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define REPEAT 1000

void bubble(int a[]) {
    for(int i = 0; i < N-1; i++)
        for(int j = 0; j < N-i-1; j++)
            if(a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

void insertion(int a[]) {
    for(int i = 1; i < N; i++) {
        int key = a[i];
        int j = i-1;

        while(j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

void quick(int a[], int low, int high) {
    if(low < high) {

        int pivot = a[high];
        int i = low - 1;

        for(int j = low; j < high; j++) {

            if(a[j] < pivot) {
                i++;

                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }

        int t = a[i+1];
        a[i+1] = a[high];
        a[high] = t;

        int p = i+1;

        quick(a, low, p-1);
        quick(a, p+1, high);
    }
}

int linearSearch(int a[], int key) {

    for(int i = 0; i < N; i++)
        if(a[i] == key)
            return i;

    return -1;
}

int binarySearch(int a[], int key) {

    int low = 0;
    int high = N-1;

    while(low <= high) {

        int mid = (low + high)/2;

        if(a[mid] == key)
            return mid;

        else if(a[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {

    int arr[N];
    int copy[N];

    int key;

    srand(time(NULL));

    /* Generate random numbers */
    for(int i = 0; i < N; i++)
        arr[i] = rand() % 10000;

    key = arr[N-1];

    clock_t start, end;

    /* Linear Search */

    start = clock();

    for(int k = 0; k < REPEAT; k++)
        linearSearch(arr, key);

    end = clock();

    printf("Linear Search  = %f seconds\n",
        (double)(end-start)/CLOCKS_PER_SEC);


    /* Bubble Sort */

    start = clock();

    for(int k = 0; k < REPEAT; k++) {

        for(int i = 0; i < N; i++)
            copy[i] = arr[i];

        bubble(copy);
    }

    end = clock();

    printf("Bubble Sort    = %f seconds\n",
        (double)(end-start)/CLOCKS_PER_SEC);


    /* Insertion Sort */

    start = clock();

    for(int k = 0; k < REPEAT; k++) {

        for(int i = 0; i < N; i++)
            copy[i] = arr[i];

        insertion(copy);
    }

    end = clock();

    printf("Insertion Sort = %f seconds\n",
        (double)(end-start)/CLOCKS_PER_SEC);


    /* Quick Sort */

    start = clock();

    for(int k = 0; k < REPEAT; k++) {

        for(int i = 0; i < N; i++)
            copy[i] = arr[i];

        quick(copy, 0, N-1);
    }

    end = clock();

    printf("Quick Sort     = %f seconds\n",
        (double)(end-start)/CLOCKS_PER_SEC);


    /* Binary Search */

    for(int i = 0; i < N; i++)
        copy[i] = arr[i];

    quick(copy, 0, N-1);

    start = clock();

    for(int k = 0; k < REPEAT; k++)
        binarySearch(copy, key);

    end = clock();

    printf("Binary Search  = %f seconds\n",
        (double)(end-start)/CLOCKS_PER_SEC);


    return 0;
}
