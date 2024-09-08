#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    // n 关 m 位英杰的奖励
    vector<vector<pair<int, int>>> award(n);
    for (int i = 0; i < m; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i) {
        int a1, a2, a3, b1, b2 ,b3;
        cin >> a1 >> a2 >> a3;
        cin >> b1 >> b2 >> b3;
        // 复位
        --b1;--b2;--b3;
        // 英杰 ： 奖励
        award[i].push_back({b1, a1});
        award[i].push_back({b2, a2});
        award[i].push_back({b3, a3});
    }
    // 记录 m 位英杰访问了多少次
    unordered_map<int, int> table;
    // 不要硬回溯！
    
    function<int(int)> dfs = [&](int idx) -> int {
        if (idx >= n) {
            return 0;
        }
        long long ans = 0;
        for (int i = 0; i < 3; ++i) {
            auto [bi, ai] = award[idx][i];
            long long t = ai;
            ++table[bi];
            if (table[bi] == 3) {
                t += c[bi];
            }
            ans = max(ans, dfs(idx + 1) + t);
            --table[bi];
        }
        return ans;
    };
    
    cout << dfs(0) << endl;


    return 0;
}
