#include <iostream>
using namespace std;
double &process()
{
    double y = 30.6;
    double &x = y;
    y += 6;
    return x;
}
int main()
{
    double x = process();
    cout<<"result: "<<x;
    return 0;
}