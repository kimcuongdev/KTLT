#include <iostream>
using namespace std;
void swap(int &v1, int &v2)
{
	int temp = v1;
	v1 = v2;
	v2 = temp;
}
void print(int a)
{
	cout<<a<<endl;
}
void (*pprint)(int);
int main()
{
	void (*pswap)(int& , int&) = swap;
	pprint = print;
	int a = 1, b = 5;
	(*pprint)(a);
	(*pprint)(b);
	cout << "Before: " << a << " " << b << endl;
	(*pswap)(a,b);  //có thể bỏ *
	cout << "After:  " << a << " " << b << endl;
	return 0;
}