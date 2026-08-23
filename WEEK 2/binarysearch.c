#include <stdio.h>
#include <time.h>

int main() {
    static int arr[1000000];

    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    int numSizes = 5;

    printf("Binary Search Time Complexity Analysis\n");
    printf("--------------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];
        int key = n - 1;
        int found = 0;

        // Create sorted array
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        clock_t start = clock();

        // Run Binary Search many times
        for (int k = 0; k < 100000; k++) {

            int low = 0;
            int high = n - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (arr[mid] == key) {
                    found = 1;
                    break;
                }
                else if (key > arr[mid]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        clock_t end = clock();

        double time_taken =
            (double)(end - start) / CLOCKS_PER_SEC;

        printf("Input Size = %d, Time = %f seconds\n",
               n, time_taken);

        if (found)
            printf("Element Found\n\n");
    }

    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
