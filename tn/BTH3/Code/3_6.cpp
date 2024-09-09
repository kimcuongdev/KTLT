#include <iostream>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    while (a!=b)
    {
        //tìm ước chung nhỏ nhất
        if (a>b) a-=b;
        if (a<b) b-=a;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}