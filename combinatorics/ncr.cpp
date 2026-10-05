// needs binpow (math/binpow.cpp)
// nCr % MOD for large n and small r, O(r + log MOD)
ll ncr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    r = min(r, n - r);
    ll num = 1, den = 1;
    for (ll i = 1; i <= r; i++) {
        num = num * ((n - r + i) % MOD) % MOD;
        den = den * (i % MOD) % MOD;
    }
    return num * binpow(den, MOD - 2) % MOD;
}
