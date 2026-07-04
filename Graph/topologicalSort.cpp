#define ll long long

bool topoSort(vector<vector<ll>> &adj) {
    ll n = adj.size();
    vector<ll> inDegree(n, 0);
    for (ll i = 1; i < n; i++) {
        for (ll node : adj[i]) {
            inDegree[node]++;
        }
    }

    queue<ll> q;
    for (ll i = 1; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    ll visited = q.size();
    while (!q.empty()) {
        ll curr = q.front();
        q.pop();
        for (ll node : adj[curr]) {
            inDegree[node]--;
            if (inDegree[node] == 0) {
                q.push(node);
                visited++;
            }
        }
    }

    if (visited == n - 1) return false;
    return true;
}