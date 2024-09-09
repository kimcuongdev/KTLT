void dfs(vector< list<int> > adj) {
    /**************************************
    Nguyễn Kim Cường-20224939-738918-2023.2 
    ***************************************/
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    while (!(S.empty()))
    {
        int u = S.top();    //xét tại đỉnh ngăn xếp
        if (!visited[u])
        {
            visited[u] = 1;     
            cout<<u<<" "<<endl; //thăm đỉnh ngăn xếp
        }
        if (!adj[u].empty())        //xét các đỉnh kề
        {
            int v=adj[u].front();
            adj[u].pop_front();     
            if (!visited[v]) S.push(v); //thêm đỉnh kề vào ngăn xếp nếu chưa thăm
        }
        else S.pop();   //nếu đã thăm hết các đỉnh kề, xóa đỉnh ngăn xếp
        
    }
}