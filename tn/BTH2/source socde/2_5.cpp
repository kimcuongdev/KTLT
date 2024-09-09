#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
using namespace std;
struct Complex {                                    //định nghĩa số phức
    double real;
    double imag;
};
Complex operator + (Complex a, Complex b) {         //đa năng hóa phép cộng
    Complex c;                                      //c=a+b
    c.real = a.real + b.real;                       //c.thực = a.thực + b.thực
    c.imag = a.imag + b.imag;                       //c.ảo = a.ảo + b.ảo
    return c;                                       //trả về c;
}
Complex operator - (Complex a, Complex b) {         //đa năng hóa phép trừ
    Complex c;                                      //c=a-b   
    c.real = a.real - b.real;                       //c.thực = a.thực - b.thực
    c.imag = a.imag - b.imag;                       //c.ảo = a.ảo - b.ảo
    return c;                                       //trả về c
}
Complex operator * (Complex a, Complex b) {         //đa năng hóa phép nhân
    Complex c;                                      //c=a*b
    c.real = a.real * b.real - a.imag * b.imag;     //c.thực = a.thực * b.thực - a.ảo * b.ảo
    c.imag = a.real * b.imag + b.real * a.imag;     //c.ảo = a.thực * b.ảo + b.thực * a.ảo
    return c;                                       //trả về c
}

Complex operator / (Complex a, Complex b) {                                             //đa năng hóa phép chia
    Complex c;                                                                          //c=a/b
    c.real = (a.real * b.real + a.imag * b.imag)/(b.real * b.real + b.imag * b.imag);   //c.thực = (a.thực*b.thực+a.ảo*b.ảo)/((mô đun b)^2)
    c.imag = (a.imag * b.real - a.real * b.imag)/(b.real * b.real + b.imag * b.imag);   //c.ảo = (a.ảo*b.thực-a.thực*b.ảo)/((mô đun b)^2)
    return c;
}
ostream& operator << (ostream& out, const Complex &a) {                                 //đa năng hóa toán tử >>
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}
int main() {
    double real_a, real_b, img_a, img_b;                    //khai báo phần thực, phần ảo
    cin >> real_a >> img_a;                                 //nhập vào phần thực, ảo của số phức a 
    cin >> real_b >> img_b;                                 //nhập vào phần thực, ảo của số phức b
    
    Complex a{real_a, img_a};                               //khai báo số phức a
    Complex b{real_b, img_b};                               //khai báo số phức b
    
    cout << a << " + " << b << " = " << a + b << endl;      //in a+b
    cout << a << " - " << b << " = " << a - b << endl;      //in a-b
    cout << a << " * " << b << " = " << a * b << endl;      //in a*b
    cout << a << " / " << b << " = " << a / b << endl;      //in a/b
    
    return 0;
}