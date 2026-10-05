vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> f;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) n /= i, cnt++;
            f.push_back({i, cnt});
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}
