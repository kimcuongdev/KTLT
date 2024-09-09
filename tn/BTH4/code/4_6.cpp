void bfs(vector< list<int> > adj) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = 1; //đánh dấu đã thăm 1
    while(!Q.empty())
    {
        int u = Q.front();  //thăm đỉnh ở đầu danh sách
        cout<<u<<" "<<endl;
        Q.pop();
        for (int v : adj[u])    //thăm các đỉnh kề với đỉnh đầu
        {
            if (!visited[v])
            {
                Q.push(v);
                visited[v] = 1;
            }
        }
    }
}