#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;

bitset<N> is_prime;
int scary_count[N];

// check if a number contains zero
bool has_zero(int x) {
    while (x) {
        if (x % 10 == 0) return true;
        x /= 10;
    }
    return false;
}

// check if all truncations (from left) are prime
bool is_scary(int x) {
    if (has_zero(x)) return false;
    string s = to_string(x);
    for (int i = 0; i < (int)s.size(); i++) {
        int val = stoi(s.substr(i));
        if (!is_prime[val]) return false;
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // sieve
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = 0;
        }
    }

    // precompute scary primes
    for (int i = 2; i < N; i++) {
        if (is_prime[i] && is_scary(i))
            scary_count[i] = 1;
    }

    // prefix sum
    for (int i = 1; i < N; i++)
        scary_count[i] += scary_count[i - 1];

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << scary_count[n] << "\n";
    }
    return 0;
}
