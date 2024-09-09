#include <iostream>
using namespace std;
template <typename T>                               //định nghĩa template function
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
//# viết hàm arr_sum
T arr_sum(T*a, int a_length, T*b, int b_length)     //arr_sum trả về kiểu tùy theo tham số truyền vào
{
    T sum=0;
    for (int i=0;i<a_length;i++)
    {
        sum += *(a+i);
    }
    for (int j=0;j<b_length;j++)
    {
        sum += *(b+j);
    }
    return sum;
}
int main() {
    int val;                                    //khai báo val
    cin >> val;                                 //nhập vào val
    {   
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;    //truyền vào mảng nguyên cho arr_sum
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;    //truyền vào mảng thực cho arr_sum
    }

    return 0;
}