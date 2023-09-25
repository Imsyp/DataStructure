#include <stdio.h>

int main(void)
{
    int i=9;
    int j=0;
    while(i<=10)
    {
        while(j<=10)
        {
            i++;
            j++;
            printf("%dtry: %d, %d ", j, i, j);
        }
    }

    return 0;
}
