// Dinic max flow, nodes 1..n; call init_flow(n), add_edge(u, v, cap), then max_flow(s, t)
// edge i goes u -> v, edges[i ^ 1] is its reverse; flow on edge i = edges[i ^ 1].cap
// after max_flow, level[u] != -1 <=> u is on the source side of the min cut
struct edge {
    int to;
    ll cap;
};
vector<edge> edges;
vector<vector<int>> adj;   // adj[u] = indices into edges
vector<int> level, ptr;

void init_flow(int n) {
    edges.clear();
    adj.assign(n + 1, {});
}

int add_edge(int u, int v, ll cap) {   // returns the edge index
    edges.push_back({v, cap});
    adj[u].push_back(edges.size() - 1);
    edges.push_back({u, 0});
    adj[v].push_back(edges.size() - 1);
    return edges.size() - 2;
}

bool bfs(int s, int t) {
    level.assign(adj.size(), -1);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int id : adj[u]) {
            if (edges[id].cap > 0 && level[edges[id].to] == -1) {
                level[edges[id].to] = level[u] + 1;
                q.push(edges[id].to);
            }
        }
    }
    return level[t] != -1;
}

ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    for (int &i = ptr[u]; i < (int)adj[u].size(); i++) {
        int id = adj[u][i], v = edges[id].to;
        if (edges[id].cap > 0 && level[v] == level[u] + 1) {
            ll got = dfs(v, t, min(f, edges[id].cap));
            if (got > 0) {
                edges[id].cap -= got;
                edges[id ^ 1].cap += got;
                return got;
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t) {
    ll flow = 0;
    while (bfs(s, t)) {
        ptr.assign(adj.size(), 0);
        while (ll f = dfs(s, t, INF)) flow += f;
    }
    return flow;
}
