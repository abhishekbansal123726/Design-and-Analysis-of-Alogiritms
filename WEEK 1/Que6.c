#include <stdio.h>

int main()
{
    int a[100], n, target, i, j;

    scanf("%d", &n);

    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &target);

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i] + a[j] == target)
                printf("(%d, %d)\n", a[i], a[j]);
        }
    }

    return 0;
}
