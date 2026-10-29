// p[i] = length of the longest palindrome of s centered at i in t = "#s0#s1#...#s(n-1)#"
// odd palindromes are centered on a character, even ones on a '#'
// the center of s[l..r] in t is l + r + 1
vector<int> manacher(string s) {
    string t = "#";
    for (char ch : s) { t += ch; t += '#'; }
    int n = t.size();
    vector<int> p(n);
    for (int i = 0, c = 0, r = 0; i < n; i++) {
        if (i < r) p[i] = min(r - i, p[2 * c - i]);
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) p[i]++;
        if (i + p[i] > r) c = i, r = i + p[i];
    }
    return p;
}