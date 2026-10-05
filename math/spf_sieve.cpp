vector<int> spf, primes;

void sieve(int n) {
    spf.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p > n) break;
            spf[i * p] = p;
        }
    }
}

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> f;
    while (x > 1) {
        int p = spf[x], cnt = 0;
        while (x % p == 0) x /= p, cnt++;
        f.push_back({p, cnt});
    }
    return f;
}
