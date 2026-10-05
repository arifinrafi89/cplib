// needs binpow (math/binpow.cpp)
vector<ll> fact, inv_fact;

void init_fact(int n) {
    fact.assign(n + 1, 1);
    inv_fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = binpow(fact[n], MOD - 2);
    for (int i = n; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
}

ll ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
