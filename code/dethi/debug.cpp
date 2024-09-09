#include <stdio.h>
int foo(int);
#define TEST (n>2)
int main()
{
    int n = 1;
    #ifdef TEST
        printf ("Reached main() n = %d\n",n);
    #endif
    
}