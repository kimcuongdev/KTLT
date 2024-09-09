#include <stdio.h>
inline int vd(int x, int y)
{
    static int a = 10;
    return (x>a ||y)? x-a+y++:x+y;
}
int main()
{
    int m =5, n=8;
    printf("%d",vd(m,n));
}