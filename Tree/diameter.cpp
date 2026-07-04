#define ll long long

void dfsDepth(ll node, ll par, vector<vector<ll>> &adj, vector<ll> &depth) {
    for (ll child : adj[node]) {
        if (par == child) continue;
        depth[child] = depth[node] + 1;
        dfsDepth(child, node, adj, depth);
    }
    return;
}

ll dfsHeight(ll node, ll par, vector<vector<ll>> &adj) {
    ll h = 0;
    for (ll child : adj[node]) {
        if (par == child) continue;
        h = max(h, 1 + dfsHeight(child, node, adj));
    }
    return h;
}


ll diameter(ll n, vector<vector<ll>> &adj) {
    vector<ll> depth(n + 1, 0);
    dfsDepth(1, 0, adj, depth);
    ll node = -1;
    ll maxDepth = -1;
    for (ll i = 1; i <= n; i++) {
        if (depth[i] > maxDepth) {
            maxDepth = depth[i];
            node = i;
        }
    }
    ll d = dfsHeight(node, 0, adj);
    return d;
}
