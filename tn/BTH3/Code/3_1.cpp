int lucas(int n) {
    /**************************************
    Nguy?n Kim Cu?ng-20224939-738918-2023.2 
    ***************************************/
    if (n==0) return 2;                     //L0 = 2
    if (n==1) return 1;                     //L1=1
    else return lucas(n-1) + lucas(n-2);    //L(n)=L(n-1)+L(n-2)
}