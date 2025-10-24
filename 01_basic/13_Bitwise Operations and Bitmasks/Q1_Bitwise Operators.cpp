// problem -> https://vjudge.net/problem/HackerRank-bitwise-operators-in-c

#include <iostream>
using namespace std;

void calculate_the_maximum(int n, int k) {
    int max_and = 0, max_or = 0, max_xor = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int aa = i & j;
            int oo = i | j;
            int xx = i ^ j;

            if (aa < k && aa > max_and) max_and = aa;
            if (oo < k && oo > max_or) max_or = oo;
            if (xx < k && xx > max_xor) max_xor = xx;
        }
    }

    cout << max_and << "\n" << max_or << "\n" << max_xor << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    calculate_the_maximum(n, k);
    return 0;
}
