#include <stdio.h>
#define R 3
#define C 3
int main()
{
    int **mt;
    mt= new int*[R];
    int *temp = new int[R*C];
    for (int i =0;i<R;i++)
    {
        mt[i] = temp;
        temp+=C;
    }
    
}