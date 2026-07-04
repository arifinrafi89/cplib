#define ll long long

vector<ll> KMP(string &s, string &p) {
    ll n = s.size(), m = p.size();
    vector<ll> LPS(m), res;
    for (ll i = 1, j = 0; i < m; ) {
        if (p[i] == p[j]) LPS[i++] = ++j;
        else if (j) j = LPS[j - 1];
        else LPS[i++] = 0;
    }
    for (ll i = 0, j = 0; i < n; ) {
        if (s[i] == p[j]) i++, j++;
        if (j == m) res.push_back(i - j), j = LPS[j - 1];
        else if (i < n && s[i] != p[j]) j ? j = LPS[j - 1] : i++;
    }
    return res;
}