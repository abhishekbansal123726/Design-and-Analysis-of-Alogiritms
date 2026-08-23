#include <stdio.h>
#include <time.h>

int main() {

    static int arr[10000];

    int sizes[] = {1000, 2000, 4000, 6000, 8000, 10000};
    int numSizes = 6;

    printf("Insertion Sort Time Complexity Analysis\n");
    printf("---------------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];

        // Reverse order array
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        clock_t start = clock();

        // Insertion Sort
        for (int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {

                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Input Size = %d, Time = %f seconds\n",
               n, time_taken);
    }

    printf("\nTime Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
