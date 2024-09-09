#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        //tinh chỉnh bằng cách đưa t ra khỏi vòng while
        if(t == 1){
            while(k--){
                int a;
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        } else {
            while(k--){
                int a;
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}