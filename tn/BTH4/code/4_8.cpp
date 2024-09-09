template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    map<T,double> c = a;                            //gán c bằng a
    for (const auto &x : b)                         //xét mỗi cặp trong b
    {                                               
        const auto it = c.find(x.first);            
        if (it != c.end())                          //nếu cặp đã tồn tại trong c
        {
            c[x.first] = max(x.second,it->second);  //cập nhật giá trị value
        }
        else c.insert(x);                           //nếu không, insert vào map
    }
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T,double>c;
    for (const auto &x : a)                     //xét mỗi key trong a
    {
        const auto it = b.find(x.first);        
        if (it != b.end())                      //nếu tìm thấy key trong b
        {   
            c[x.first] = min(x.second,it->second);  //cập nhật giá trị value
        }
    }
    return c;
}