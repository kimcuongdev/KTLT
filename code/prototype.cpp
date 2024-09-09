#include <iostream>
using namespace std;
int myFunc(int , int k = 3);
int myFunc(int a, int k)
{
	return a+k;
}
int main()
{
	cout<<myFunc(2)<<endl;
	cout<<myFunc(3,9);
}