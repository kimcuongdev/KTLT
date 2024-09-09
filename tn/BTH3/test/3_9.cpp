#include <iostream>
using namespace std;
int n,k1,k2,x[201];
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
void inp() 
{
    cin>>n>>k1>>k2;
}
void out()
{
    for (int i=1;i<=n;i++)
    {
        cout<<x[i];
    }
    cout<<"\n";
}
bool check(int pos,int value, int count) //kiểm tra tại ngày pos, có được nghỉ hay không
{										 //với số ngày đã làm việc là count
    if (pos==1) return true;			 //ngày đầu tiên có thể nghỉ hoặc làm
    else								 //các ngày khác
    {
        if (value == 0)					 //nếu như muốn nghỉ
        {
            return count>=k1;			 //phải thỏa mãn số ngày đã đi làm >= k1
        }
        if (value == 1)					 //nếu muốn đi làm tiếp
        {
            return count<k2;			 //phải thỏa mãn số ngày đi làm < k2
        }
    }
    return false;
}
void Try(int pos, int count)			 //quay lui
{
    for (int value=0;value<=1;value++)
    {
        if (check(pos,value,count)){		
        	x[pos] = value;
        	int new_count=(x[pos] == 1)?(count+1):0;		//cập nhật số ngày đã đi làm
        if (pos == n)
        {
            if (x[pos] == 0|| new_count>=k1) out();			//đủ n ngày, in kết quả
        }
        else Try(pos+1,new_count);
		}
    }
}
int main()
{
    inp();
    Try(1,0);
    return 0;
}