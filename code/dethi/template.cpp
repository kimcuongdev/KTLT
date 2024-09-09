#include <iostream>
using namespace std;
template <typename T> T f(T a, T &b)
{
    b++;
    a++;
    return a * b;
}
int main()
{
    int a=1,b=1;
    float c = 4.0, d = 5.0;
    printf("%d %.0f",f(f(a,b),b),f(c,d));
    printf("\n%d",b);
}