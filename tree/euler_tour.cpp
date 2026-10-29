// euler tour, nodes 1..n; call init_euler(root, n) once
// subtree of u = positions tin[u]..tout[u] (1-indexed, fits fenwick), node at position i is ver[i]
// u is an ancestor of v <=> tin[u] <= tin[v] && tin[v] <= tout[u]
// ver, tin, tout 1 indexed
// tin[u]  = timer value when dfs enters node u
// tout[u] = timer value when dfs leaves node u (timer of the last node visited inside node u's subtree)
// ver[i]  = node that dfs entered at time i (inverse of tin, tin[ver[i]] == i)
vector<vector<int>> adj;
vector<int> tin, tout, ver;
int timer;

void dfs(int u, int p) {
    tin[u] = ++timer;
    ver[timer] = u;
    for (int v : adj[u])
        if (v != p) dfs(v, u);
    tout[u] = timer;
}

void init_euler(int root, int n) {
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    ver.assign(n + 1, 0);
    timer = 0;
    dfs(root, 0);
}
