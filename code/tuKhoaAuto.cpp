#include <iostream>
using namespace std;

auto maxval(auto x, auto y)
{
	static int cnt = 1;
	cout<<cnt++<<": ";
	return (x>y)?x:y;
}
int main()
{
	cout<<maxval('5','a')<<endl;
	int i=maxval(3,4);
	cout<<i<<endl;
	cout<<maxval(5,8)<<endl;
	double j=maxval(5.1,6.7);
	cout<<j<<endl;
	char c=maxval('a','6');
	cout<<c<<endl;
	cout<<maxval(9,10)<<endl;
	return 0;
}