#include <iostream>
using namespace std;
int main()
{
    int n=5;
    void* p;
    p = &n;
    //*p += 10;
    *(int*)p += 10;
    cout<<*(int*)p;
}