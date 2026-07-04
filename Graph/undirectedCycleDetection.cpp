#define ll long long

vector<ll> cycle;

bool dfs(ll node, vector<vector<ll>> &adj, vector<bool> &visited, vector<bool> &anc, vector<ll> &cycle) {
    if (anc[node]) {
        cycle.push_back(node);
        return true;
    }
    if (visited[node]) return false;
    visited[node] = true;
    anc[node] = true;
    cycle.push_back(node);
    for (ll child : adj[node]) {
        if (dfs(child, adj, visited, anc, cycle)) return true;
    }
    cycle.pop_back();
    anc[node] = false;
    return false;
}

bool cycleDetection(ll n, vector<vector<ll>> &adj) {
    vector<bool> visited(n + 1, false), anc(n + 1, false);
    bool possible = false;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            possible = dfs(i, adj, visited, anc, cycle);
            if (possible) break;
        }
    }
    if (!possible) return false;
    ll node = cycle.back();
    reverse(all(cycle));
    while (cycle.back() != node) 
        cycle.pop_back();
    reverse(all(cycle));
    return true;
}