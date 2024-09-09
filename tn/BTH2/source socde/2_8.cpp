#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
using namespace std;
int main() {
    int val1, val2;                 //khai báo val1, val2
    cin >> val1 >> val2;            //nhập vào val1, val2
    vector< vector<int> > a = {     //khai báo vector các vector a
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    sort(a.begin(),a.end(),             //gọi hàm sort
        [](vector<int> &p, vector<int> &q) //tham số thứ 3 truyền vào hàm sort 
        {                                  //là hàm để định nghĩa luật sắp xếp
            return accumulate(p.begin(),p.end(),0) 
                 > accumulate(q.begin(),q.end(),0);
        });
    //luật: tổng phần tử vector trước lớn hơn tổng phần tử vector sau
    //sử dụng hàm accumulate để tính tổng
    for (const auto &v : a) {           //với mỗi vector trong a
        for (int it : v) {              //với mỗi phần tử trong vector
            cout << it << ' ';          //in ra
        }
        cout << endl;
    }
    return 0;
}