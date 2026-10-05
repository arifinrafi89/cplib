// needs prefix_function (string/prefix_function.cpp)
// 0-indexed start positions of every occurrence of p in s
vector<int> kmp(string s, string p) {
    vector<int> pi = prefix_function(p), res;
    for (int i = 0, j = 0; i < (int)s.size(); i++) {
        while (j > 0 && s[i] != p[j]) j = pi[j - 1];
        if (s[i] == p[j]) j++;
        if (j == (int)p.size()) {
            res.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return res;
}
