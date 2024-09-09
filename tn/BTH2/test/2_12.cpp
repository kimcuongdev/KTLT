#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
	/**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
using namespace std;
vector<pair<int,int>> a;	//khai báo vector lưu các cặp số
void input()  //nhập dữ liệu
{
	int key,value;
	while (cin>>key && cin>>value)
	{
		pair<int,int> temp = make_pair(key, value);
		a.push_back(temp); 
	}
}
void output()		//xuất dữ liệu
{
	for (int i=0;i<a.size();i++)
	{
		cout<<a[i].first<<" "<<a[i].second<<endl;
	}
}
int main()
{
	input();
	sort(a.begin(),a.end(),[] (pair<int,int>p, pair<int,int> q)		//sử dụng hàm nặc danh định nghĩa sắp xếp
	{
		if (p.second != q.second) return p.second > q.second;		//nếu value khác nhau, so sánh value
		else return p.first > q.first;								//ngược lại, so sánh key
	});
	output();
	return 0;
}