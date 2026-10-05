// tree diameter in edges, nodes 1..n; endpoints are a and b
vector<vector<int>> adj;
vector<int> dist;
int a, b;

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dist[v] = dist[u] + 1;
        dfs(v, u);
    }
}

int diameter(int n) {
    dist.assign(n + 1, 0);
    dfs(1, 0);
    a = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    dist.assign(n + 1, 0);
    dfs(a, 0);
    b = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    return dist[b];
}
