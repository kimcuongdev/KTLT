#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    return sqrt(x*x + y*y); //ch^2 = x^2 + y^2;
}

int main(){
    float x, y;             //khai báo x,y
    scanf("%f%f", &x, &y);  //nhập x,y
    
    float z = get_hypotenuse(x, y); //gọi hàm
    printf("z = %.2f\n", z);        //in cạnh huyền
    
    return 0;
}