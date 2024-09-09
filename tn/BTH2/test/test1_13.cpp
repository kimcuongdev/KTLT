#include<bits/stdc++.h>
using namespace std;

struct bigNum {
    char sign;
    char num[1001];
};

//nhập số lớn
void input(bigNum &num1, bigNum &num2){
    string tmp;
    cin >> tmp;
    num1.sign = tmp[0];
    int lens1 = tmp.length() - 1;
    for(int i=0; i<lens1; i++){
        num1.num[1000-lens1+i+1] = tmp[i+1];
    }
    for(int i=0; i<1000-lens1+1; i++) num1.num[i] = '0';

    cin >> tmp;
    num2.sign = tmp[0];
    int lens2 = tmp.length() - 1;
    for(int i=0; i<lens2; i++){
        num2.num[1000-lens2+i+1] = tmp[i+1];
    }
    for(int i=0; i<1000-lens2+1; i++) num2.num[i] = '0';
}

//cộng hai số
void add(char res[], const char *num1, const char *num2){
    int c = 0;  //nhớ c

    for(int i=1000; i>=0; i--){
        int tmp = (int)num1[i] - 48 + (int)num2[i] - 48 + c;
        c = tmp / 10;
        res[i] = tmp % 10 + 48;
    }
}

//trừ hai số (num1>num2)
void sub(char res[], const char *num1, const char *num2){
    int c = 0;

    for(int i=1000; i>=0; i--){
        int tmp1 = (int)num1[i] - 48;
        int tmp2 = (int)num2[i] - 48;

        if(tmp1 >= tmp2 + c){
            res[i] = tmp1 - tmp2 - c + 48;
            c = 0;
        } else {
            tmp1 = tmp1 + 10;
            res[i] = tmp1 - tmp2 - c + 48;
            c = 1;
        }
    }
}

//nhân hai số
void multi(char res[], const char *num1, const char *num2){
    //khởi tạo kết quả
    for(int i=0; i<1001; i++) res[i] = '0';

    for(int i=1000; i>=0; i--){
        //khởi tạo số rỗng
        char tmp[1001];
        for(int j=0; j<1001; j++) tmp[j] = '0';

        int k = 1000;
        int c = 0, sum = 0; //nhân có nhớ c
        for(int j=1000; j>=0; j--){
            sum = ((int)num1[i] - 48) * ((int)num2[j] - 48) + c;
            tmp[k] = (sum % 10) + 48;
            c = sum / 10;
            k--; 
        }
        
        add(res,tmp,res);
    }
}

// check num1 >= num2
bool check(const char *num1, const char *num2){
    int foo1, foo2;
    for(foo1 = 0; foo1 < 1001; foo1++){
        if(num1[foo1] != '0') break;
    }

    for(foo2 = 0; foo2 < 1001; foo2++){
        if(num2[foo2] != '0') break;
    }

    if(foo1 > foo2) return false;
    else if(foo1 < foo2) return true;
    else { // foo1 == foo2
        int foo = foo1;
        while(foo < 1001){
            if(num1[foo] < num2[foo]) return false;
            else if (num1[foo] > num2[foo]) return true;
            else {
                foo++;
            }
        }
    }

    return true;
}

//đa năng hóa toán tử "+"
bigNum operator + (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){ //+ hai số dương
        res.sign = '1';
        add(res.num,num1.num,num2.num);
    } else if(num1.sign == '1' && num2.sign == '0'){    //+ số dương với số âm
        if(check(num1.num,num2.num)){
            res.sign = '1';
            sub(res.num,num1.num,num2.num);
        } else {
            res.sign = '0';
            sub(res.num,num2.num,num1.num);
        }
    } else if(num1.sign == '0' && num2.sign == '1'){ //+ số âm với số dương
        if(check(num1.num,num2.num)){
            res.sign = '0';
            sub(res.num,num1.num,num2.num);
        } else {
            res.sign = '1';
            sub(res.num,num2.num,num1.num);
        }
    } else { // both negative
        res.sign = '0';
        add(res.num,num1.num,num2.num);
    }
    return res;
}

//đa năng hóa toán tử "-"
bigNum operator - (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '0'){  //trừ số dương với số âm
        num2.sign = '1';
        res = num1 + num2;
    } else if(num1.sign == '1' && num2.sign == '1'){ //trừ hai số dương
        num2.sign = '0';
        res = num1 + num2;
    } else if(num1.sign == '0' && num2.sign == '1'){    //trừ số âm với số dương
        num2.sign = '0';
        res = num1 + num2;
    } else {                                        //trừ hai số âm
        num2.sign = '1';
        res = num1 + num2;
    }
    return res;
}

//đa năng hóa toán tử "*"
bigNum operator * (bigNum num1, bigNum num2){
    bigNum res;

    if(num1.sign == '1' && num2.sign == '1'){            //nhân hai số dương
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
    } else if(num1.sign == '1' && num2.sign == '0'){    //nhân số dương và số âm
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
    } else if(num1.sign == '0' && num2.sign == '1'){    //nhân số âm và số dương
        res.sign = '0';
        multi(res.num,num1.num,num2.num);
    } else {                                            //nhân hai số âm
        res.sign = '1';
        multi(res.num,num1.num,num2.num);
    }
    return res;
}

//in số lớn
void printBigNumber(bigNum number){
    if (number.sign == '0') cout << "-";
    int start;
    for(start=0; start<1001; start++)
        if(number.num[start] != '0') break;

    if (start == 1001) {
        cout << "0";
    } else {
        for(int i = start; i<1001; i++)
            cout << number.num[i];
    }
    cout << endl;
}

int main(){
    bigNum num1, num2;    //khai báo a và b
    input(num1,num2);

    bigNum so3, so4;                        //khởi tạo số 3 và 4
    so3.sign = '1', so4.sign = '1';
    for(int i=0; i<1000; i++){
        so3.num[i] = '0';
        so4.num[i] = '0';
    }
    so3.num[1000] = '3';
    so4.num[1000] = '4';

    bigNum res = num1*num2 - so3 * num1 + so4 * num2; //res = a*b - 3a +4b

    printBigNumber(res);    //in
}
