#define ll long long
#define pll pair<ll, ll>

class MaxPrefixQuery {
private:
    vector<vector<ll>> mat;
    vector<ll> pref;   
public:
    MaxPrefixQuery(vector<pll> &v) {
        ll n = v.size();
        mat.resize(n);
        for (ll i = 0; i < n; i++) mat[i] = {v[i].first, v[i].second, i};

        sort(all(mat), [](vector<ll> &x, vector<ll> &y){
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] > y[1];
        });

        pref.resize(n);
        ll best = -1;
        for (ll i = 0; i < n; i++) {
            if (best == -1 || mat[i][1] > mat[best][1]) best = i;
            pref[i] = best;
        }
    }

    ll query(ll k) {
        auto it = upper_bound(all(mat), k, [](ll k, vector<ll> &p){
            return k < p[0];
        });
        if (it == mat.begin()) return -1;
        ll idx = (ll)(it - mat.begin()) - 1;
        return mat[pref[idx]][2];
    }
};
