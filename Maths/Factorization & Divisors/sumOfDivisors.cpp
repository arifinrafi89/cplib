#define ll long long
#define pll pair<ll, ll>

ll binExp(ll a, ll b, ll M) {
    ll res = 1;
    while(b) {
        if (b % 2 == 1) {
            res *= a;
            res %= M;
        }
        a *= a;
        a %= M;
        
        b >>= 1;
    }
    return res;
}

ll modInv(ll n, ll M) {
    return binExp(n, M - 2, M);
}

ll sumOfDivisors(vector<pll> &f, ll M) {
    ll res = 1;
    for (auto [p, e] : f) {
        ll num = (binExp(p, e + 1, M) - 1 + M) % M;
        ll den = (p - 1 + M) % M;
        ll cur = num * modInv(den, M) % M;
        res = res * cur % M;
    }
    return res;
}