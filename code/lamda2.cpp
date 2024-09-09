#include <iostream>
using namespace std;
int main()
{
    auto x1 = [](int i){return i;};
    cout<<x1(3)<<endl;
    int m = 0,n = 0;
    auto funcN = [&, n](int a) mutable
    {
        m = ++n + a;
    };
    auto funcM = [&, m](int a) mutable
    {
        m = ++n + a;
        n += 10;
    };
    funcN(4);
    funcM(4);
    cout<<m<<" "<<n<<endl;
}