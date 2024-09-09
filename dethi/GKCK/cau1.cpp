#include <iostream>
using namespace std;
int main()
{
    char s1[6] = {'H','a','n','o','i'};
    char s2[6] = "Hanoi";
    int res = strcmp(s1,s2);
    cout<<(res < 0);
}