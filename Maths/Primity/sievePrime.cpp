#define ll long long
#define pll pair<ll, ll>

class SievePrime {
private:
    vector<bool> prime;
public:
    SievePrime(ll n) {
        prime.assign(n + 1, true);
        prime[0] = prime[1] = false;
        for (ll i = 2; i <= n; i++) {
            if (prime[i]) {
                for (ll j = i * 2; j <= n; j += i)
                    prime[j] = false;
            }
        }
    }

    bool isPrime(ll x) {
        return prime[x];
    }

};
