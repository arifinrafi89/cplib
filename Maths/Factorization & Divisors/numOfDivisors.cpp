// count of divisors from prime factorization
#define ll long long
#define pll pair<ll, ll>

ll countOfDivisors(vector<pll> &f, ll M) {
    ll res = 1;
    for (auto [p, e] : f)
        res = res * (e + 1) % M;
    return res;
}