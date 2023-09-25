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
        while(pivot >= arr[low] && low <= right)    
            low++;

        while(pivot <= arr[high] && high >= (left+1))
            high--;
/*
low <= right로 설정해두면 low가 배열의 정렬 범위를 넘어서지만 low는 마지막 Swap 과정에 포함되지 않기 때문에 괜찮다.
하지만, 더 깔끔하게 low가 배열 범위에서 벗어나지 않고, high가 pivot과 겹치지 않게 하기 위해서는 
두 범위를 low < right과 high > left+1로 설정하는 것이 더 깔끔할 것으로 예상된다.
*/

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
    //int arr[3] = {3, 3, 3};

    int len = sizeof(arr)/sizeof(int);
    int i;

    QuickSort(arr, 0, len-1);

    for(i=0; i<len; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}