// Kosaraju, nodes 1..n; comp[u] = component id, ids are in topological order
// (an edge u -> v between components always has comp[u] < comp[v])
vector<vector<int>> adj, radj;   // radj = edges reversed
vector<int> order, comp;
vector<bool> vis;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int c) {
    comp[u] = c;
    for (int v : radj[u])
        if (comp[v] == -1) dfs2(v, c);
}

int scc(int n) {   // returns the number of components
    vis.assign(n + 1, false);
    order.clear();
    for (int u = 1; u <= n; u++)
        if (!vis[u]) dfs1(u);
    comp.assign(n + 1, -1);
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
        if (comp[order[i]] == -1) dfs2(order[i], c++);
    return c;
}
