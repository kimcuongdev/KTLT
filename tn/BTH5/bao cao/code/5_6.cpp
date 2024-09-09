#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
char cal(double a){
    if (a < 4) return 'F';
    //thêm điều kiện rẽ nhánh else if
    else if (4 <= a && a < 5.5) return 'D';
    else if (5.5 <= a && a < 7) return 'C';
    else if (7 <= a && a < 8.5) return 'B';
    else if (8.5 <= a) return 'A';
}

int main(){
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        double a; //sửa kiểu dữ liệu của a từ int -> double
        cin >> a;
        char calA = cal(a); //tính trước calA để khỏi phải tính lại
        if (calA == 'A') ++A;
        //thêm điều kiện rẽ nhánh else if để không phải lặp lại việc xét điểm
        else if (calA == 'B') ++B; 
        else if (calA == 'C') ++C;
        else if (calA == 'D') ++D;
        else if (calA == 'F') ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
