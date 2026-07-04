#define ll long long
#define pll pair<ll, ll>


ll MST (ll s, vector<vector<ll>> &adj, vector<bool> &visited) {

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    ll sum = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pll node = pq.top();
        pq.pop();
        if (visited[node.second] == true) continue;
        visited[node.second] = true;
        sum += node.first;
        for (pll child : adj[node.second]) {
            if (visited[child.second] == true) continue;
            pq.push({child.first, child.second});
        }
    }
    return sum;
}

