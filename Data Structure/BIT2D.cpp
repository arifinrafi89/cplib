// input vector 0 indexed, tree 1 indexed
#define ll long long

class  BIT2D {
private:
    ll n, m;
    vector<vector<ll>> tree;

    ll lsb(ll idx) {
        return idx & -idx;
    }

    ll sum(ll x, ll y) {
        ll res = 0;
        for (ll i = x; i > 0; i -= lsb(i)) 
            for (ll j = y; j > 0; j-= lsb(j))
                res += tree[i][j];
        return res;
    }

public:
    BIT2D(vector<vector<ll>> &mat) {
        n = mat.size();
        m = mat[0].size();
        tree.assign(n + 1, vector<ll> (m + 1, 0));
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= m; j++)
                update(i, j, mat[i - 1][j - 1]);
    }

    void update(ll x, ll y, ll val) {
        for (ll i = x; i <= n; i += lsb(i))
            for (ll j = y; j <= m; j += lsb(j))
                tree[i][j] += val;
    }

    ll query(ll x1, ll y1, ll x2, ll y2) {
        return sum(x2, y2) 
               - sum(x1 - 1, y2) 
               - sum(x2, y1 - 1)
               + sum(x1 - 1, y1 - 1);
    }
};
