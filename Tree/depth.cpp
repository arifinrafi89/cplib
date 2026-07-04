#define ll long long

void dfsDepth(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &depth) {
    for (ll child : adj[node]) {
        if (par == child) continue;
        depth[child] = depth[node] + 1;
        dfsDepth(child, node, adj, depth);
    }
    return;
}