#define ll long long

class LCA {
private:
    ll n;
    ll K;
    vector<vector<ll>> anc;
    vector<ll> level;

    void dfs(ll u, ll par, vector<vector<ll>> &adj) {
        anc[u][0] = par;
        level[u] = level[par] + 1;
        for (ll k = 1; k < K; k++) 
            anc[u][k] = anc[anc[u][k - 1]][k - 1];
        for (ll v : adj[u]) {
            if (v == par) continue;
            dfs(v, u, adj);
        }
    }

public:
    LCA(ll root, ll _n, vector<vector<ll>> &adj) {
        n = _n;
        K = 64 - __builtin_clzll(n + 1);
        anc.assign(n + 1, vector<ll>(K, 0));
        level.assign(n + 1, 0);
        level[0] = -1;        
        dfs(root, 0, adj);    
    }

    ll lca(ll u, ll v) {
        if (level[u] > level[v]) swap(u, v);
        ll diff = level[v] - level[u];
        for (ll k = 0; k < K; k++) 
            if (diff & (1LL << k)) v = anc[v][k];
        if (u == v) return u;
        for (ll k = K - 1; k >= 0; k--) {
            if (anc[u][k] != anc[v][k]) {
                u = anc[u][k];
                v = anc[v][k];
            }
        }
        return anc[u][0];
    }

    ll getAnc(ll u, ll d) {
        for (ll k = 0; k < K; k++) 
            if (d & (1LL << k)) u = anc[u][k];
        return u;
    }

    ll getDist(ll u, ll v) {
        ll g = lca(u, v);
        return level[u] + level[v] - 2 * level[g];
    }
};

