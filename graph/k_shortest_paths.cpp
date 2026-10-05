// k shortest walks from s to t (vertices may repeat), ascending
vector<vector<pair<int, int>>> adj;   // adj[u] = {v, w}

vector<ll> k_shortest(int s, int t, int k) {
    vector<int> cnt(adj.size());
    vector<ll> res;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty() && (int)res.size() < k) {
        auto [d, u] = pq.top();
        pq.pop();
        if (cnt[u] == k) continue;
        cnt[u]++;
        if (u == t) res.push_back(d);
        for (auto [v, w] : adj[u]) pq.push({d + w, v});
    }
    return res;
}
