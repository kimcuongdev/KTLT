#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int>::size_type sz;
    vector<int> foo;
    sz = foo.capacity();
    cout << "Initial capacity of foo: " << foo.capacity() << endl;
    cout<<"making foo grow:\n";
    for (int i = 0;i < 100; ++i)
    {
        foo.push_back(i);
        if (sz != foo.capacity())
        {
            sz = foo.capacity();
            cout<<"capacity changed: "<<sz<<endl;
        }
    }
    vector<int> bar;
    sz = bar.capacity();
    bar.resize(100);
    cout << "Initial capacity of bar: " << bar.capacity() << endl;
    bar.push_back(1);
    cout<<"change: "<<bar.capacity()<<endl;
    bar.push_back(1);
    cout<<"change: "<<bar.capacity()<<endl;
    cout<<"making bar grow:\n";
    for (int i=0;i<99;++i)
    {
        bar.push_back(i);
        if (sz != bar.capacity())
        {
            sz = bar.capacity();
            cout<<"capacity changed: "<<sz<<endl;
        }
    }
    return 0;
}