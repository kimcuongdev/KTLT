#include <iostream>
using namespace std;
void myPrint(int a)
{
    cout<<a<<" ";
}
void myPrint(int a, int b = 5)
{
    cout<<a<<" "<<b;
}
int main()
{
    myPrint(5);
    return 0;
}