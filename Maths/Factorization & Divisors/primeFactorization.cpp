#define ll long long
#define pll pair<ll, ll>

vector<pll> factorize(ll n) {
    vector<pll> f;
    if (n <= 1) return f;
    ll ct = 0;
    while ((n & 1LL) == 0) {
     n >>= 1;
     ct++;
    }
    if (ct) f.push_back({2, ct});

    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0) {
            ct = 0;
            while (n % i == 0) {
                n /= i;
                ct++;
            }
            f.push_back({i, ct});
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}