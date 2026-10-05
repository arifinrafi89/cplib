// nodes 1..n, returns MST cost or -1 if the graph is disconnected
vector<vector<pair<int, int>>> adj;   // adj[u] = {v, w}, add both directions

ll prim(int n) {
    vector<bool> vis(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    ll cost = 0;
    int taken = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cost += w;
        taken++;
        for (auto [v, wt] : adj[u])
            if (!vis[v]) pq.push({wt, v});
    }
    return taken == n ? cost : -1;
}
