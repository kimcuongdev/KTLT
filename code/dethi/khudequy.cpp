#include <iostream>
using namespace std;
int S(int n)
{
    if (n==1) return 1;
    else if(n==2) return 5;
    else if (n==3) return 12;
    else if (n==4) return 22;
    else if (n==5) return 35;
    else if (n==6) return 51;
    else
    {
        int x,y;
        int x1 = 0, x2 = 2, x3 = 4, x4 = 6, x5 = 8, x6 = 10;
        int y1 = 1, y2 = 2, y3 = 3, y4 = 4, y5 = 5, y6 = 6;
        int s = 51;
        for (int i = 7;i < n; i++)
        {
            x = x1 - y3 + x4 + y6;
            y = y1 - x3 + y4 + x6;
            s = s + x + y;
            x1 = x2; x2 = x3; x3 = x4; x4 = x5; x5 = x6; x6 = x;
            y1 = y2; y2 = y3; y3 = y4; y4 = y5; y5 = y6; y6 = y;
        }
        return s;
    }
}

int main()
{
    cout<<S(1)<<endl;
    cout<<S(2)<<endl;
    cout<<S(3)<<endl;
    cout<<S(4)<<endl;
    cout<<S(5)<<endl;
    cout<<S(6)<<endl;
    cout<<S(7)<<endl;
    cout<<S(8)<<endl;
    cout<<S(9)<<endl;
    cout<<S(10)<<endl;
}