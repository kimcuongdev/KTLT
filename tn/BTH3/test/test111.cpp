#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

const int inf = 10000;

int n, r, c[inf][inf], cmin = inf, f, fopt, x[inf], visited[inf];

void inp() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(c[i][j], cmin);
        }
    }
}

void reset() {
    for (int i = 0; i < n; i++) {
        x[i] = 0;
        visited[i] = 0;
    }
}

void Try(int k, const vector<int> &a) {
    for (int i = 1; i < a.size() - 1; i++) {
        if (!visited[a[i]] && c[x[k - 1]][a[i]] != 0) {
            x[k] = a[i];
            visited[a[i]] = 1;
            f += c[x[k - 1]][x[k]];
            if (k == a.size() - 2) {
                if (c[x[k]][a.back()] != 0 && f + c[x[k]][a.back()] < fopt) {
                    fopt = f + c[x[k]][a.back()];
                }
            } else {
                if (f + cmin * (a.size() - k) < fopt) Try(k + 1, a);
            }
            f -= c[x[k - 1]][x[k]];
            visited[a[i]] = 0;
        }
    }
}

int main() {
    inp();
    vector<vector<int>> vt(r);
    string line;
    for (int i = 0; i < r; i++) {
        getline(cin, line);
        stringstream ss(line);
        int value;
        while (ss >> value) {
            vt[i].push_back(value);
        }
    }
    for (int i = 0; i < r; i++) {
        x[0] = vt[i][0];
        visited[vt[i][0]] = 1;
        f = 0;
        fopt = inf;
        Try(1, vt[i]);
        cout << ((fopt < inf) ? fopt : 0) << "\n";
        reset();
    }
}
