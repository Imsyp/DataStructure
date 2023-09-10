#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
    int temp;
    temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    int low = left+1;
    int high = right;

    while(low <= high)
    {
        while(pivot > arr[low])
            low++;

        while(pivot < arr[high])
            high--;

        if(low <= high)
            Swap(arr, low, high);
    }

    Swap(arr, left, high);
    return high;
}

void QuickSort(int arr[], int left, int right)
{
    if(left <= right)
    {
        int mid = Partition(arr, left, right);
        QuickSort(arr, left, mid - 1);
        QuickSort(arr, mid + 1, right);
    }


}

int main(void)
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    //  arr[3] = {3, 3, 3};

    int len = sizeof(arr)/sizeof(int);
    int i;

    QuickSort(arr, 0, len-1);

    for(i=0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}