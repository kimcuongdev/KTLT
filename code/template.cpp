#include <iostream>
using namespace std;
template <typename T>
void print(T x)
{
	static int count = 0;
	count++;
	cout<<"Lan goi thu: "<<count<<endl;
	cout<<x<<endl;
}
int main()
{
	print(1);
	print(5);
	print("hello");
	print(1.2);
	print("world");
	return 0;
}