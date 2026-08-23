#include <stdio.h>
#include <time.h>

static int arr[10000];
static int temp[10000];

void merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(low, mid);
        mergeSort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main() {

    int sizes[] = {1000, 2000, 4000, 6000, 8000, 10000};
    int numSizes = 6;

    printf("Merge Sort Time Complexity Analysis\n");
    printf("-----------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];

        // Reverse order array
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        clock_t start = clock();

        mergeSort(0, n - 1);

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Input Size = %d, Time = %f seconds\n",
               n, time_taken);
    }

    printf("\nTime Complexity: O(n log n)\n");
    printf("Space Complexity: O(n)\n");

    return 0;
}
