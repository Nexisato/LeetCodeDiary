#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        // 箱子容量，玩具数量，填充物数量
        int N, n, c;
        cin >> N >> n >> c;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int total = accumulate(arr.begin(), arr.end(), 0);
        bool res = false;
        if (total + c < N) {
            res = false;
        }
        vector<bool> visited(n, false);
        sort(arr.begin(), arr.end());
        function<bool(int)> dfs =[&](int cur) -> bool {
            if (cur > N) return false;
            if (N - cur <= c) return true;
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    if (dfs(cur + arr[i]))
                        return true;
                    visited[i] = false;
                }
            }
            return false;
        };
        res = dfs(0);

        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}