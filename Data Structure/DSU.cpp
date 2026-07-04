#define ll long long

class DSU {
private:
    vector<ll> par;
    vector<ll> sz;

    void build(ll n) {
        par.resize(n + 1);
        for (ll i = 1; i <= n; i++)
            par[i] = i;
        sz.assign(n + 1, 1);
    }

public:
    DSU(ll n) {
        build(n);
    }

    ll find(ll u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    } 

    void add(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;

    }

    ll returnSize(ll u) {
        u = find(u);
        return sz[u];
    }

};