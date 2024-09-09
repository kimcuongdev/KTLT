#include <iostream>
using namespace std;
int main()
{
    char s[6] = "xyz";
    const char *ptr = s;
    s[1] = 'Y';
    // ptr += 1;
    // *(ptr + 1) += 1;
    ptr += 1;
    cout<<ptr;
    return 0;
}