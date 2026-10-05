vector<bool> is_prime;
vector<int> primes;

void sieve(int n) {
    is_prime.assign(n + 1, true);
    is_prime[0] = false;
    if (n >= 1) is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) primes.push_back(i);
}
