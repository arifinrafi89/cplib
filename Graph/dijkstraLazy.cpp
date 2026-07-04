#define ll long long
#define pll pair<ll, ll>


void dijkstra(ll start, vector<vector<pll>> &adj, vector<ll> &dist) {
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()) {
        pll curr = pq.top();
        pq.pop();
        if (curr.first > dist[curr.second]) continue;
        for (pll node : adj[curr.second]) {
            if (dist[node.second] > curr.first +  node.first) {
                dist[node.second] = curr.first +  node.first;
                pq.push({dist[node.second], node.second});
            }
        }   
    }
    return;
}