// needs binpow (math/binpow.cpp)
// f = prime factorization as {p, e} pairs, e.g. from factorize()
ll divisor_product(auto f) {
    ll res = 1, cnt = 1; // cnt = number of divisors so far, mod (MOD - 1)
    for (auto [p, e] : f) {
        ll q = binpow(p, 1LL * e * (e + 1) / 2);
        res = binpow(res, e + 1) * binpow(q, cnt) % MOD;
        cnt = cnt * (e + 1) % (MOD - 1);
    }
    return res;
}
