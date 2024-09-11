#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct business_t {
    int start;
    int end;
    int profit;
};

int main() {
   int n;
   cin >> n;
   vector<int> bases(n + 1, 0);
   int m;
   cin >> m;
   vector<business_t> tasks;
   for (int i = 0; i < m; ++i) {
        business_t cur;
        cin >> cur.start >> cur.end >> cur.profit;
        tasks.push_back(cur);
   }

   sort(tasks.begin(), tasks.end(), [&](const business_t& t1, const business_t& t2) {
        return t1.start < t2.start;
   });

    // dp[i] 表示以 i 为起点，到右端点的最大利润和
   vector<int> dp(m + 1, 0);
   for (int idx = m - 1; idx >= 0; --idx) {
        int l = idx, r = m;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (tasks[mid].start > tasks[idx].end) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }// 找到第一个右端点
        dp[idx] = max(dp[idx + 1], dp[r] + tasks[idx].profit);
   }

    cout << dp[0] << endl;





	return 0;
}