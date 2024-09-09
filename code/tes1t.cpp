#include <iostream>
using namespace std;
int main(){
    int a = 10, b = 15;
    int *p = &a, *q = &b;
    *p-- += b ^ ~++a;
    *p += 2;
    cout << a << ", " << b;
}
