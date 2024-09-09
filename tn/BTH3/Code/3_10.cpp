#include <iostream>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int n,h,x[20];
void inp()
{
	cin>>n>>h;
}
void out()
{
	for (int i=1;i<=n;i++)
	{
		cout<<x[i];
	}
	cout<<"\n";
}
void Try(int pos,int count)			//quay lui-nhánh cận in ra xâu nhị phân độ dài n có h số 1
{
	for (int i=0;i<=1;i++)
	{
		x[pos] = i;						
		int new_count=count;
		if (x[pos] == 1){
			new_count = count+1;
		}
		if (pos==n){				
			if (new_count == h)out();	//nếu độ dài là n mà có h số 1 thì in ra
		}
		else if (n-pos>=h-new_count) Try(pos+1,new_count); //nếu vị trí trống còn lại không đủ cho số lượng số 1, cắt nhánh
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		inp();
		Try(1,0);
	}
}