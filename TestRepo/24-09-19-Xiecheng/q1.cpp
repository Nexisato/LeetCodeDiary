#include <iostream>
using namespace std;


// 这个题硬搜是没有意义的，先向下再向右，到最后再反复横跳
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    long long res = 0;
    if (k <= n - 1) {
        res = k * (k + 1) * m / 2;
    }
    else if (k <= n + m - 2) {
        long long row_sum = n * (n - 1) * m / 2;
        k -= (n - 1);
        res = row_sum + k * (n - 1) * m + (k + 1) * k / 2;
    } else {
        long long before = n * (n - 1) * m / 2 + (m - 1) * m / 2 + (m - 1) * (n - 1);
        k -= (n + m - 2);
        res += ((k / 2) * (2 * (n - 1) * m + 2 * m - 3));
        if (k % 2) {
            res += ((n - 1) * m + m - 2);
        }
    }

    cout << res << endl;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        solve();
    }

    return 0;
}
