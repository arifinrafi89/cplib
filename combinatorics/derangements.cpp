vector<ll> der;

void init_der(int n) {
    der.assign(n + 1, 0);
    der[0] = 1;
    for (int i = 2; i <= n; i++) der[i] = (i - 1) * (der[i - 1] + der[i - 2]) % MOD;
}
