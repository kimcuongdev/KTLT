Vector cross_product(Vector a, Vector b) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    tuple <double, double, double> c;
    //cong thuc tinh tich co huong
    get<0>(c) = get<1>(a) * get<2>(b) - get<1>(b) * get<2>(a);
    get<1>(c) = get<0>(b) * get<2>(a) - get<0>(a) * get<2>(b);
    get<2>(c) = get<0>(a) * get<1>(b) - get<0>(b) * get<1>(a);
    return c;
}