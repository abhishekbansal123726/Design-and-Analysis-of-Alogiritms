#include <stdio.h>
#include <time.h>

static int arr[10000];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high) {

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

void quickSort(int low, int high) {

    if (low < high) {

        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main() {

    int sizes[] = {1000, 2000, 4000, 6000, 8000, 10000};
    int numSizes = 6;

    printf("Quick Sort Time Complexity Analysis\n");
    printf("-----------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];

        // Reverse order array
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        clock_t start = clock();

        quickSort(0, n - 1);

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Input Size = %d, Time = %f seconds\n",
               n, time_taken);
    }

    printf("\nAverage Time Complexity: O(n log n)\n");
    printf("Worst Case Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(log n) average\n");

    return 0;
}
