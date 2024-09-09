#include <stdio.h>
int main()
{
    int i = 10, j = 0;
    if ( (j=i+10) || (i))
    {
        printf("%d",j);
    }
    return 0;
}