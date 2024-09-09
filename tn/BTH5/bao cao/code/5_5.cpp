#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int main(){
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) //sửa lỗi a % 100 == 0 thành a % 400 == 0
            found = true;
            cout << "Yes"; //in ra và kết thúc chương trình ngay khi tìm thấy
            return 0;

        }
    cout << "No";
}