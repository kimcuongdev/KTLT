double* maximum(double* a, int size){
    /****************************************
    Nguy?n Kim Cu?ng - 4939 - 738918 - 2023.2
    *****************************************/
    double *max;
    max = a;
    if (a==NULL) return NULL;
    for (int i=0;i<size;i++)
    {
        if (*(a+i) > *max) max = a+i;
    }
    return max;

}