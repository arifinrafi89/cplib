// returns a vector of k shortest paths from src to dest
#define ll long long
#define pll pair<ll, ll>


vector<ll> shpa(ll n, ll src, ll dest, ll k, vector<vector<pll>> &adj) {
 
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    priority_queue<ll> d[n + 1];
    pq.push({0, src});
    d[src].push(0);
    while (!pq.empty()) {
        pll node = pq.top();
        pq.pop();
        if (node.first > d[node.second].top()) continue;
        for (pll child : adj[node.second]) {
            if (d[child.second].size() < k) {
                d[child.second].push({node.first + child.first});
                pq.push({node.first + child.first, child.second});
            }
            else if (d[child.second].top() > node.first + child.first) {
                d[child.second].pop();
                d[child.second].push({node.first + child.first});
                pq.push({node.first + child.first, child.second});
            }
        }
    }

    vector<ll> res;
    while (!d[dest].empty()) {
            res.push_back(d[dest].top());
            d[dest].pop();
        }
        return res;
}
