#include <bits/stdc++.h>
using namespace std;
int fact(int n) 
{
    int fact = 1;
    if (n<0) throw("ngu");
    for (int i=n;i>=1;i--)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    try
    {
        printf("%d",fact(-1));
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
}