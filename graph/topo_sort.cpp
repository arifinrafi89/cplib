// Kahn's algorithm, nodes 1..n; returns the order, or empty if there is a cycle
vector<vector<int>> adj;

vector<int> topo_sort(int n) {
    vector<int> indeg(n + 1), order;
    for (int u = 1; u <= n; u++)
        for (int v : adj[u]) indeg[v]++;
    queue<int> q;
    for (int u = 1; u <= n; u++)
        if (indeg[u] == 0) q.push(u);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0) q.push(v);
    }
    if ((int)order.size() < n) return {};
    return order;
}
