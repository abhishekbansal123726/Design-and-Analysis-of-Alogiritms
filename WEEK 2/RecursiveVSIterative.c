#include <stdio.h>
#include <time.h>

unsigned long long recursive(int n) {
    if(n <= 1)
        return 1;

    return n * recursive(n-1);
}

unsigned long long iterative(int n) {
    unsigned long long fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main() {

    int n = 20;
    int repeat = 1000000;

    unsigned long long result;

    clock_t start, end;

    /* Recursive */
    start = clock();

    for(int i = 0; i < repeat; i++)
        result = recursive(n);

    end = clock();

    double recursiveTime =
        (double)(end-start)/CLOCKS_PER_SEC;


    /* Iterative */
    start = clock();

    for(int i = 0; i < repeat; i++)
        result = iterative(n);

    end = clock();

    double iterativeTime =
        (double)(end-start)/CLOCKS_PER_SEC;


    printf("Factorial = %llu\n", result);

    printf("Recursive Time = %f seconds\n",
           recursiveTime);

    printf("Iterative Time = %f seconds\n",
           iterativeTime);

    printf("\nTime Complexity:\n");
    printf("Recursive = O(n)\n");
    printf("Iterative = O(n)\n");

    printf("\nSpace Complexity:\n");
    printf("Recursive = O(n)\n");
    printf("Iterative = O(1)\n");

    return 0;
}
