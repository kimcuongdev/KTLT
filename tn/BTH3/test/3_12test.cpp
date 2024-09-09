#include <bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int>> graph;
vector<bool> visited;

void inp() {
    cin >> n >> k;
    cin >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

void Try(int pos, int edgesUsed) {
    if (edgesUsed == k) {
        res++;
        return;
    }

    for (int v : graph[x[pos - 1]]) {
        if (!visited[v]) {
            visited[v] = true;
            Try(pos + 1, edgesUsed + 1);
            visited[v] = false;
        }
    }
}

int main() {
    inp();
    int res = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        Try(1, 0);
        visited[i] = false;
    }
    cout << res / 2;
    return 0;
}
