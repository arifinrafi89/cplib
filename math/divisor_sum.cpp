// needs binpow (math/binpow.cpp)
// f = prime factorization as {p, e} pairs, e.g. from factorize()
ll divisor_sum(auto f) {
    ll res = 1;
    for (auto [p, e] : f) {
        ll q = p % MOD, cur;
        if (q == 1) cur = (e + 1) % MOD;
        else cur = (binpow(q, e + 1) - 1 + MOD) % MOD * binpow(q - 1, MOD - 2) % MOD;
        res = res * cur % MOD;
    }
    return res;
}
