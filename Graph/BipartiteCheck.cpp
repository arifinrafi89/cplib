#define ll long long

bool bipartiteCheck(ll n, vector<vector<ll>> &adj, vector<ll> &colour) {
    
    colour.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        if (colour[i] == 0) {
            colour[i] = 1;
            queue<ll> q;
            q.push(i);
            while (!q.empty()) {
                ll node = q.front();
                q.pop();
                for (ll child : adj[node]) {
                    if (colour[child] == colour[node]) return false;
                    if (colour[child] == 0) {
                        q.push(child);
                        if (colour[node] == 1) colour[child] = 2;
                        else colour[child] = 1;
                    }
                }
            }
        }
    }
    return true;
}
