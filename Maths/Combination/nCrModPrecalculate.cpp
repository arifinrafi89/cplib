#define ll long long

class Combination {
private:
    ll n, M;
    vector<ll> fact, inv, invFact;

    void init() {
        fact[0] = 1;
        invFact[0] = 1;
        for (ll i = 1; i <= n; i++) {
            if (i == 1) {
                inv[i] = 1;
            } else {
                ll a = inv[i - (M % i)];
                ll b = (M / i) + 1;
                inv[i] = (a * b) % M;
            }
            fact[i] = (fact[i - 1] * i) % M;
            invFact[i] = (invFact[i - 1] * inv[i]) % M;
        }
    }

public:
    Combination(ll _n, ll _M) : n(_n), M(_M), fact(n + 1), inv(n + 1), invFact(n + 1) {
        init();
    }

    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % M) * invFact[n - r]) % M;
    }
};