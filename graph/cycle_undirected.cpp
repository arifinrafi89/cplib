// undirected, nodes 1..n; returns a cycle as [a, ..., a], or empty if the graph is a forest
vector<vector<int>> adj;
vector<int> par;
vector<bool> vis;
int cyc_start, cyc_end;

bool dfs(int u, int p) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            cyc_start = v;
            cyc_end = u;
            return true;
        }
        par[v] = u;
        if (dfs(v, u)) return true;
    }
    return false;
}

vector<int> find_cycle(int n) {
    par.assign(n + 1, -1);
    vis.assign(n + 1, false);
    for (int s = 1; s <= n; s++) {
        if (!vis[s] && dfs(s, 0)) {
            vector<int> cyc = {cyc_start};
            for (int v = cyc_end; v != cyc_start; v = par[v]) cyc.push_back(v);
            cyc.push_back(cyc_start);
            return cyc;
        }
    }
    return {};
}
