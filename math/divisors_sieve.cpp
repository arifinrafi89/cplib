vector<vector<int>> divs;

void divisor_sieve(int n) {
    divs.assign(n + 1, {});
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i)
            divs[j].push_back(i);
}
