#define ll long long

ll binExp(ll a, ll b, ll M) {
    ll res = 1;
    while(b) {
        if (b % 2 == 1) {
            res *= a;
            res %= M;
        }
        a *= a;
        a %= M;
        
        b >>= 1;
    }
    return res;
}

ll modInv(ll n, ll M) {
	return binExp(n, M - 2, M);
}

ll nCr(ll n, ll r, ll M) {
	r = min(r, n - r);
	ll res = 1;
	for (ll i = 1; i <= r; i++) {
		res = (res * (n - r + i)) % M;
		res = res * modInv(i, M);
		res %= M;
	}
	return res;
}