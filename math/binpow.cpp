ll binpow(ll a, ll b) {
    a %= MOD;
    if (a < 0) a += MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
