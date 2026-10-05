// needs dsu (ds/dsu.cpp)
// edges = {w, u, v}, returns MST cost or -1 if the graph is disconnected
ll kruskal(int n, vector<array<int, 3>> edges) {
    sort(edges.begin(), edges.end());
    dsu d(n);
    ll cost = 0;
    int used = 0;
    for (auto [w, u, v] : edges) {
        if (d.unite(u, v)) {
            cost += w;
            used++;
        }
    }
    return used == n - 1 ? cost : -1;
}
