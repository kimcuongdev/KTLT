#include <iostream>
using namespace std;
int main()
{
    int a =256;
    char c = '\0';
    double d = 1e-8;
    float f = 0.1;
    cout<<sizeof(a)<<sizeof(d)<<sizeof(f)<<sizeof(c);
}