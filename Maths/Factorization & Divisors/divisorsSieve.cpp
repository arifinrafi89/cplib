#define ll long long

class DivisorsSieve {
private:
    vector<vector<ll>> divisors;
public:
    DivisorsSieve(ll n) {
        divisors.resize(n + 1);
        for (ll i = 1; i <= n; i++) {
            for (ll j = i; j <= n; j += i) {
                divisors[j].push_back(i);
            }
        }
    }

    vector<ll> getDivisors(ll x) {
        return divisors[x];
    }

    ll numOfDivisors(ll x) {
        return divisors[x].size();
    }
};
