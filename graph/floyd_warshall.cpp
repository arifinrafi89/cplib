vector<vector<ll>> dist;

// nodes 1..n, all-pairs shortest paths, dist[i][j] = INF if j is unreachable from i
// setup: dist.assign(n + 1, vector<ll>(n + 1, INF)); dist[i][i] = 0; for each edge dist[u][v] = min(dist[u][v], w)
void floyd_warshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}