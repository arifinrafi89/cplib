#define ll long long
#define pll pair<ll, ll>

void dijkstra(ll idx, ll n, vector<vector<pll>> &adj, vector<ll> &d) {
    
    vector<bool> visited(n + 1, false);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, idx});
    d[idx] = 0;
    while (!pq.empty()) {
        pll node = pq.top();
        pq.pop();
        if (visited[node.second]) continue;
        visited[node.second] = true;
        for (pll child : adj[node.second]) {
            if (visited[child.second] == true) continue;
            ll newDist = child.first + node.first;
            if (newDist < d[child.second]) {
                pq.push({newDist, child.second});
                d[child.second] = newDist;
            }
        }
    }
}