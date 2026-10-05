// binary lifting, nodes 1..n; call init_lca(root, n) once
const int LOG = 20;   // 2^20 > 1e6
vector<vector<int>> adj;
vector<int> depth;
vector<array<int, LOG>> up;

void dfs(int u, int p) {
    up[u][0] = p;
    for (int k = 1; k < LOG; k++) up[u][k] = up[up[u][k - 1]][k - 1];
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void init_lca(int root, int n) {
    depth.assign(n + 1, 0);
    up.assign(n + 1, {});
    dfs(root, 0);
}

int kth_ancestor(int u, int k) {   // 0 if it doesn't exist
    for (int i = 0; i < LOG; i++)
        if (k >> i & 1) u = up[u][i];
    return u;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; k--)
        if (up[u][k] != up[v][k]) u = up[u][k], v = up[v][k];
    return up[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}
