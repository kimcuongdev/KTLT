#include <iostream>
using namespace std;
int x = 4;
int& myFunc()
{
	x+=4;
	return x;
}
int main()
{
	cout<<"x = "<<x<<endl;
	cout<<"&x = "<<&x<<endl;
	cout<<"x = "<<myFunc()<<endl;
	cout<<"&myFunc = "<<&myFunc()<<endl;
	myFunc() = 20;
	x=myFunc();
	cout<<"x = "<<x<<endl;
	return 0;
}