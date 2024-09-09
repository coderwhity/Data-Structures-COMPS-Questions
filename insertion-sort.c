#include <stdio.h>

void main()
{
    int arr[] = {23, 24, 245, 6, 23};
    int n = 5;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("\nSorted Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}