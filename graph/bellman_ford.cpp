// nodes 1..n, returns false if a negative cycle is reachable from s, otherwise dist[] holds the shortest distances
vector<vector<pair<int, int>>> adj;   // adj[u] = {v, w}
vector<ll> dist;

bool bellman_ford(int n, int s) {
    dist.assign(n + 1, INF);
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        bool changed = false;
        for (int u = 1; u <= n; u++) {
            if (dist[u] == INF) continue;
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    changed = true;
                }
            }
        }
        if (!changed) return true;
        if (i == n) return false;   // still relaxing on the n-th pass => negative cycle
    }
    return true;
}