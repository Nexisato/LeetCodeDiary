#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最少不会少于 m 个
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int res = n;
    for (int l = 0, r = 0; r < n; ++r) {
        if (r - l + 1 == m) {
            if (arr[r] - arr[l] <= k)
                --res;
            ++l;
        }
    }

    cout << res << endl;


    return 0;
}
