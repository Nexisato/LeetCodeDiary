#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 线段树怎么构建...
class segment_tree {
private:
    vector<int> arr;
    int n;
public:
    segment_tree(int _n): n(_n), arr(vector<int>(_n + 1, 0)) {};

    void update(int idx, int val) {
        
    }
};

int main() {
    ios::sync_with_stdio(false);


    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        dp[i] = dp[i - 1] + arr[i - 1];

    vector<long long> max_sum(n + 1, 0);
    for (int len = 1; len <= n; ++len) {
        long long cur_sum = -1;
        for (int l = 1; l + len - 1 <= n; ++l) {
            int r = l + len - 1;
            long long cur = dp[r] - dp[l - 1];
            cur_sum = max(cur, cur_sum);
            
        }
        max_sum[len] = cur_sum;
    }


    auto solve = [&](int l, int r) {
        long long res = *max_element(max_sum.begin() + l, max_sum.begin() + r + 1);
        cout << res << endl;

    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        solve(l, r);

    }

    return 0;
}