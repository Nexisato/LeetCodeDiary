#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long res = 0;

    // for any i < j, arr[i] > arr[j]
    // dp[i] 代表以 arr[i] 结尾的递减子序列的数量
    vector<long long> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (arr[j] > arr[i])
                dp[i] = (dp[j] + dp[i]) % MOD;
    }
    for (int i = 0; i < n; ++i) {
        res = (res + dp[i]) % MOD;
    }
    

    cout << res << endl;


    return 0;
}