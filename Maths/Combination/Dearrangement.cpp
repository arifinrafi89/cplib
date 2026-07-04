#define ll long long

class Derangement {
private:
    ll n, M;
    vector<ll> drng;

    void init() {
        drng[0] = 1;
        if (n >= 1) drng[1] = 0;
        for (ll i = 2; i <= n; i++) {
            drng[i] = ((i - 1) * (drng[i - 1] + drng[i - 2]) % M) % M;
        }
    }

public:
    Derangement(ll _n, ll _M) : n(_n), M(_M), drng(n + 1) {
        init();
    }

    ll D(ll x) {
        if (x < 0) return 0;
        return drng[x];
    }
};