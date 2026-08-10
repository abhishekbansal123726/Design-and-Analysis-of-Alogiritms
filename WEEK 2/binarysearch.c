#include <stdio.h>

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int key, low = 0, high = 4, mid;

    printf("Enter element to search: ");
    scanf("%d", &key);

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
        {
            printf("Element found at index %d", mid);
            return 0;
        }
        else if(key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Element not found");

    return 0;
}
