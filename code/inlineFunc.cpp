#include <iostream>
#include <cmath>
using namespace std;
inline double delta(int k, int m)
{
    return sqrt(k*k + m*m);
}
inline int max(int a, int b)
{
    return (a > b) ? a : b;
}
inline int qq()
{
    return 3 + 5;
}
int main()
{
    double k = 6, m = 9;
    cout<<sqrt(k*k + m*m)<<endl;
    cout<<delta(k,m)<<endl;
    cout<<delta(3,4)<<endl;
    cout<<((k>m)?k:m)<<endl;
    cout<<max(k,m)<<endl;
    cout<<2*qq()<<endl;
    return 0;
}