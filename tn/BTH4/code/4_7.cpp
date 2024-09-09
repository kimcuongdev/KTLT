template<class T>
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> c;
    //lần lượt thêm các phần tử của a,b vào c
    for (T x : a)   
    {
        c.insert(x);
    }
    for (T y : b)
    {
        c.insert(y);
    }
    return c;
}

template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> c;
    //thêm các phần tử xuất hiện ở cả a và b vào c
    for (T x : a)
    {
        if (b.find(x) != b.end())
        {
            c.insert(x);
        }
    }
    return c;
}