// static array, O(1) range query [l, r], 0-indexed
// works for min, max, gcd (change both min calls)
struct sparse_table {
    vector<vector<ll>> t;   // t[k][i] = min of a[i .. i + 2^k - 1]

    sparse_table(vector<ll> a) {
        int n = a.size(), K = __lg(n) + 1;
        t.assign(K, a);
        for (int k = 1; k < K; k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                t[k][i] = min(t[k - 1][i], t[k - 1][i + (1 << (k - 1))]);
    }

    ll query(int l, int r) {
        int k = __lg(r - l + 1);
        return min(t[k][l], t[k][r - (1 << k) + 1]);
    }
};
