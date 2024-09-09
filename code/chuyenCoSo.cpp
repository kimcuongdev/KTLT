#include <bits/stdc++.h>
using namespace std;
//de quy
void chuyenCoSo(int base, int n)
{
    char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if (n<=0)
    {
        return;
    }
    chuyenCoSo(base,n/base);
    printf("%c",digit[n%base]);
}
void chuyenCoSo_kodequy(int base, int n)
{
    char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char res[100];
    int i=0;
    while (n>0)
    {
        res[i++] = digit[n%base];
        n=n / base;  
    }
    // res[i]='\0';
    i--;
    for (;i>=0;i--)
    {
        printf("%c",res[i]);
    }
}
int main()
{
    chuyenCoSo(16,64544);
    printf("\n");
    chuyenCoSo_kodequy(2,2);
}