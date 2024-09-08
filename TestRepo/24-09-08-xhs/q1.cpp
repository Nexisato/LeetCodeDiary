#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long res = 0;
    sort(a.begin(), a.end());
    int mid = n / 2;
    vector<int> b(n, 0);
    bool even = true;
    for (int l = 0, r = n - 1, idx = n - 1; idx >= 0; --idx) {
        if (even) {
            b[l] = a[idx];
            ++l;
            even = false;
        } else {
            b[r] = a[idx];
            --r;
            even = true;
        }
    }
    // (i + 1) * (n - i) ，
    // 左边表示从左边到该元素的所有可能的起始点的数量，
    // 右边表示从该元素到数组右边所有的可能的终点的数量
    for (int i = 0; i < n; ++i) {
        res += (long long)b[i] * (i + 1) * (n - i);
    }


    cout << res << endl;
    

    return 0;
}