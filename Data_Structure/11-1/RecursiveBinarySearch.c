#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
    printf("first: %d, last: %d, target:%d ", first, last, target);

    int mid;
    if(ar[first]>target || ar[last]<target)
        return -1;

    mid = ((double)(target-ar[first]) /(ar[last]-ar[first])*(last-first))+first;

    if(ar[mid] == target)
        return mid;
    else if(target < ar[mid])
        return BSearchRecur(ar, first, mid-1, target);
    else
        return BSearchRecur(ar, mid+1, last, target);
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 7);
    if(idx == -1)
        printf("Å½»ö ½ÇÆÐ \n");
    else
        printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int)-1, 2);
    if(idx == -1)
        printf("Å½»ö ½ÇÆÐ \n");
    else
        printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

    return 0;
}