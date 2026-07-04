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

ll productOfDivisors(vector<pll> &f, ll M) {
    ll phi = M - 1;
    ll twoPhi = 2 * phi;
    ll d2 = 1 % twoPhi;
    for (auto [p, e] : f) {
        d2 = (d2 * ((e + 1) % twoPhi)) % twoPhi;
    }
    ll nMod = 1;
    for (auto [p, e] : f) {
        nMod = (nMod * binExp(p % M, e, M)) % M;
    }
    bool oddD = (d2 & 1);
    ll expMod = oddD ? ((d2 - 1) / 2) % phi : (d2 / 2) % phi;
    ll res = binExp(nMod, expMod, M);
    if (!oddD) return res;
    ll rootN = 1;
    for (auto [p, e] : f) {
        rootN = (rootN * binExp(p % M, e / 2, M)) % M;
    }
    return (res * rootN) % M;
}
