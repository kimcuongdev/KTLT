#include <iostream>
using namespace std;
int main()
{
    int i = 10, j = 0;
    if ( i || (j = i + 10))
    {
        printf("%d %d\n",i,j);
    }
    if ( (j = i + 10) || i)
    {
        printf("%d %d\n",i,j);
    }
    if ( (j = i + 10) || (i = j + 10))
    {
        printf("%d %d\n",i,j);
    }
    return 0;
}