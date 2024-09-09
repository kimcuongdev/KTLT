#include <iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
#define expr 2 + 5
int main()
{
    int i = 4;
    int j = 8;
    cout<<max(2,4)<<endl;
    cout<<max(++i,j--)<<endl;//++i > j-- ? ++i : j--
    cout<<2*expr<<endl;
}