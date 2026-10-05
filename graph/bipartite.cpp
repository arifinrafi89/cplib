// BFS 2-coloring, nodes 1..n; if bipartite, color[u] is 0 or 1 (the two sides)
vector<vector<int>> adj;
vector<int> color;

bool is_bipartite(int n) {
    color.assign(n + 1, -1);
    for (int s = 1; s <= n; s++) {
        if (color[s] != -1) continue;
        color[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
