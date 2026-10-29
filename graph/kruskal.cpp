vector<vector<ll>> edges;   // {w, u, v}

// needs dsu (ds/dsu.cpp), nodes 1..n, returns MST cost or -1 if the graph is disconnected
ll kruskal(int n) {
    sort(edges.begin(), edges.end());
    dsu d(n);
    ll cost = 0;
    int used = 0;
    for (auto &e : edges) {
        ll w = e[0], u = e[1], v = e[2];
        if (d.unite(u, v)) {
            cost += w;
            used++;
        }
    }
    return used == n - 1 ? cost : -1;
}