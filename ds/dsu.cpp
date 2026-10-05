struct dsu {
    vector<int> par, sz;

    dsu(int n) : par(n + 1), sz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int size(int x) { return sz[find(x)]; }
};
