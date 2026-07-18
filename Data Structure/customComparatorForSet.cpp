#define ll long long

struct compare {
    bool operator()(ll a, ll b) const {
        return a > b;
    }
};

// set<ll, compare>