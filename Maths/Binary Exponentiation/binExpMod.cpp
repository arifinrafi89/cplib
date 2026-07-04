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