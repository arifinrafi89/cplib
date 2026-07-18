#include<ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

struct hashFunc {
    ll C = 467826378675846483;
    ll RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    ll operator()(uint64_t x) const {
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};

gp_hash_table<ll, ll, hashFunc>