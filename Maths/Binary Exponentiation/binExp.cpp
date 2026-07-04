#define ll long long

ll binExp(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b % 2 == 1) {
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}