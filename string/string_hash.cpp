// polynomial hash mod 2^61 - 1 with a random base, get(l, r) = hash of s[l..r]
const uint64_t HMOD = (1ULL << 61) - 1;
const uint64_t BASE = mt19937_64(chrono::steady_clock::now().time_since_epoch().count())() % (HMOD - 256) + 256;

uint64_t hmul(uint64_t a, uint64_t b) {
    __uint128_t c = (__uint128_t)a * b;
    uint64_t r = (c & HMOD) + (c >> 61);
    return r >= HMOD ? r - HMOD : r;
}

struct string_hash {
    vector<uint64_t> h, pw;

    string_hash(string s) : h(s.size() + 1), pw(s.size() + 1) {
        pw[0] = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            h[i + 1] = (hmul(h[i], BASE) + s[i]) % HMOD;
            pw[i + 1] = hmul(pw[i], BASE);
        }
    }

    uint64_t get(int l, int r) {
        return (h[r + 1] + HMOD - hmul(h[l], pw[r - l + 1])) % HMOD;
    }
};
