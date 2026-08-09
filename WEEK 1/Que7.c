#include <stdio.h>

int main()
{
    int a[100], n, k, i, j, temp;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &k);

    for(i=0; i<k; i++)
    {
        temp = a[n-1];

        for(j=n-1; j>0; j--)
            a[j] = a[j-1];

        a[0] = temp;
    }

    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}
