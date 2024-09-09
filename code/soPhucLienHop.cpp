#include <bits/stdc++.h>
using namespace std;
struct soPhuc{
    int thuc;
    int ao;
};
soPhuc operator ~ (soPhuc soPhuc)
{
    soPhuc.ao = -soPhuc.ao;
    return soPhuc;
}
void inSP(soPhuc c)
{
    if (c.ao > 0)
    {
        printf("%d+%di",c.thuc,c.ao);
    }
    else if (c.ao == 0)
    {
        printf("%d",c.thuc);
    }
    else if (c.thuc == 0)
    {
        printf("%di",c.ao);
    }
    else printf("%d%di",c.thuc,c.ao);
}
soPhuc newSP(int r, int i)
{
    soPhuc c;
    c.thuc = r;
    c.ao = i;
    return c;
}
int main()
{
    soPhuc a = newSP(3,-4);
    soPhuc b = ~a;
    inSP(a);
    printf("\n");
    inSP(b);
}