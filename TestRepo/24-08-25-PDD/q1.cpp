#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        vector<int> edges(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            int a, b, e;
            cin >> a >> b >> e;
            edges[i] = e;
        }
        sort(edges.begin(), edges.end(), [&](int a, int b) { return a > b; });
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; ++i)
            prefix[i] = prefix[i - 1] + edges[i - 1];

        int res = INT32_MIN;
        for (int i = 0; i < n; ++i) {
            int cur = arr[i] + prefix[n - 1 - i];   // i + 1 个联通块 + n - 1 - i 条边
            res = max(res, cur);
        }
        cout << res << endl;
    
    }

    return 0;
}
