// 1-indexed, point add, prefix / range sum
struct fenwick {
    int n;
    vector<ll> bit;

    fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, ll val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }

    ll sum(int i) {
        ll res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    ll sum(int l, int r) { return sum(r) - sum(l - 1); }
};
