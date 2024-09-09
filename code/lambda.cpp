#include <iostream>
using namespace std;
void stdio_doing(int n)
{
	n=n+10;
	cout<<n<<" ";
}
void for_each(int *arr, int n, void(*func)(int a))
{
	for (int i=0;i<n;i++)
	{
		func(*(arr+i));
	}
}
int main()
{
	int arr[] = {1,2,3,4,5};
	int n=5;
	for_each(arr,n,[] (int a){
		a=a+10;
		cout<<a<<" ";
	});
	cout<<"\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}