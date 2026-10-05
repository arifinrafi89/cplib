// rooted tree, nodes 1..n; fills depth[] and par[] (par[root] = 0)
vector<vector<int>> adj;
vector<int> depth, par;

void dfs(int u, int p) {
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
