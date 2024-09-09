vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    vector<int> d(adj.size(),INT_MAX);
    d[0] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //{đỉnh, khoảng cách}, ưu tiên khoảng cách nhỏ
    pq.push({0,0});
    while(!pq.empty())
    {
        pair<int,int> top = pq.top();
        pq.pop();
        int u = top.first;
        int du = top.second;
        for (const auto it : adj[u])
        {
            int v = it.first;
            int uv = it.second;
            //relaxation
            if (d[v]>du + uv)
            {
                d[v] = du + uv;
                pq.push({v,d[v]});
            }
        }
    }
    return d;
}