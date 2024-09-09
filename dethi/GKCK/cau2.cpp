#include <iostream>
using namespace std;
int main()
{
    int M[][4]={{1,2,3},{4,5},};
    int m[] = {1,2,3,,,8};
    int x = 5;
    int y = 7;
    int *p = &x;
    int &r = x; //r tham chieu den x
    *p+=2;
    y+=r;
    cout<<x<<" "<<y;
}