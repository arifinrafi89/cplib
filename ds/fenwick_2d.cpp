// 1-indexed, point add, prefix / rectangle sum
struct fenwick_2d {
    int n, m;
    vector<vector<ll>> bit;

    fenwick_2d(int n, int m) : n(n), m(m), bit(n + 1, vector<ll>(m + 1)) {}

    void add(int x, int y, ll val) {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                bit[i][j] += val;
    }

    ll sum(int x, int y) {
        ll res = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                res += bit[i][j];
        return res;
    }

    ll sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
};
