double area(Point a, Point b, Point c) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    //cong thuc s = (1/2)*(x1y2- x2y1)
    return fabs((b.first - a.first)*(c.second - a.second) - (c.first - a.first)*(b.second - a.second))/2;;
}