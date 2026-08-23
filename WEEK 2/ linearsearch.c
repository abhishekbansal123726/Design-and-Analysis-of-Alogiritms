#include <stdio.h>
#include <time.h>

int main() {
    static int arr[1000000];

    int sizes[] = {10000, 50000, 100000, 500000, 1000000};
    int numSizes = 5;

    printf("Linear Search Time Complexity Analysis\n");
    printf("-------------------------------------\n");

    for (int s = 0; s < numSizes; s++) {

        int n = sizes[s];
        int key = n - 1;
        int found = 0;

        // Create array
        for (int i = 0; i < n; i++)
            arr[i] = i;

        clock_t start = clock();

        // Run Linear Search many times
        for (int k = 0; k < 100; k++) {

            for (int i = 0; i < n; i++) {

                if (arr[i] == key) {
                    found = 1;
                    break;
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

    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(1)\n");

    return 0;
}
