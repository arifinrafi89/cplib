// f = prime factorization as {p, e} pairs, e.g. from factorize()
ll divisor_count(auto f) {
    ll res = 1;
    for (auto [p, e] : f) res = res * (e + 1) % MOD;
    return res;
}
