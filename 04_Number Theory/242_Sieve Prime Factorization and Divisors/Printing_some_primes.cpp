/******************************************************************************

                              بسم الله الرحمان الرحيم
author:mfaiz_1

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define fr_3(i,n)      for(int i=0; i<(n); i++)
#define fb_3(i,a,n)    for(int i=(a); i<=(n); i++)
#define srt_3(v)       sort(v.begin(),v.end())         
#define mxe_3(v)       *max_element(v.begin(),v.end())     
#define mne_3(v)       *min_element(v.begin(),v.end())     
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

const int MXN = 100000000;   // 1e8
bitset<MXN+1> sieve;         // use bitset (memory efficient)

inline int power(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

void solve() {
    sieve.set(); 
    sieve[0] = sieve[1] = 0;

    // sieve
    for (int i = 2; (long long)i * i <= MXN; i++) {
        if (sieve[i]) {
            for (long long j = 1LL * i * i; j <= MXN; j += i) {
                sieve[j] = 0;
            }
        }
    }

    // print primes with index ≡ 1 mod 100
    int idx = 0;
    for (int i = 2; i <= MXN; i++) {
        if (sieve[i]) {
            idx++;
            if (idx % 100 == 1) {
                cout << i << "\n";
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    solve();

    return 0;
}
