#include <iostream>
using namespace std;
int func(int a, int b = 5)
{
    return a + b;
}
int main()
{
    cout<<func(5);
    // cout<<func(5,15);
}