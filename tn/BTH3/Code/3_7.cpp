#include <bits/stdc++.h>
using namespace std;
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
struct state {
    int i, j, old_L;
    // Constructor
    state(int _i = 0, int _j = 0, int _L = 0) : i(_i), j(_j), old_L(_L) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n + 1];
    stack<state> s;
    // Number of consecutive suffix 1's
    int L = 0;
    s.push(state(1, 0, 0)); // Push initial state with old_L set to 0

    while (!s.empty()) {
        state &top = s.top();
        // Nếu tìm thấy một dãy nhị phân mới
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }

        // Khôi phục giá trị L cũ nếu j > 0
        if (top.j > 0) L = top.old_L;

        // Nếu đã duyệt qua tất cả các giá trị con
        if (top.j > 1) {
            s.pop();
            continue;
        }

        // Chỉ tiếp tục nếu ràng buộc cho phép
        if (L + 1 < k || top.j == 0) {
            x[top.i] = top.j; // Gán giá trị hiện tại (0 hoặc 1) vào dãy
            top.old_L = L; // Lưu giá trị L hiện tại
            L = top.j ? L + 1 : 0; // Cập nhật L cho trạng thái tiếp theo
            s.push(state(top.i + 1, 0, L)); // Đẩy trạng thái tiếp theo vào stack
        }

        ++top.j; // Chuyển sang giá trị tiếp theo cho vị trí hiện tại (0 sang 1)
    }
    return 0;
}
