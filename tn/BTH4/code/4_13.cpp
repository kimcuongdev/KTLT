#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
	/**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
void inp()
{
	cin>>s;
}
//thay 0 bằng -1
//đếm số xâu con có tổng bằng 0
//kí hiệu tổng(i,j) là tổng xâu con từ vị trí i đến j
//tổng(i,j) = tổng(0,j) - tổng(0,i) = 0
//nếu xuất hiện chỉ số i và j có tổng bằng nhau
//thì chắc chắn từ i tới j có một xâu con thỏa mãn
ll calc(string s)
{
	ll cnt=0,res=0;
	//khởi tạo bảng băm để lưu số lần lặp lại của mỗi tổng
	unordered_map<ll,ll> mp;
	//khởi tạo giá trị của tổng 0
	mp[0] = 1;
	for (int i=0;i<s.length();i++)
	{
		//tính tổng ở vị trí i
		cnt += (s[i] == '1') ? 1 : -1;
		//nếu tổng được lặp lại, tìm thêm được xâu con thỏa mãn
		//số lượng xâu tăng thêm = số lần lặp lại của tổng (do ghép xâu mới vào các xâu cũ) 
		res += mp[cnt];
		//tăng số lần lặp lại của tổng lên 1
		mp[cnt]++; 
	}
	return res;
}
int main()
{
	freopen("input.txt","r",stdin);
	// freopen("test.out","w",stdout);
	inp();
	cout<<calc(s);
}