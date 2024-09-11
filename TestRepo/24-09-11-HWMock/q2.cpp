#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> boxes;
    for (int i = 0; i < n; ++i) {
        int l, w, h;
        cin >> l >> w >> h;
        boxes.push_back(vector<int>({l, w, h}));
    }    
    sort(boxes.begin(), boxes.end());
    int res = 0;
    vector<int> dp(n, 0);
    dp[0] = boxes[0][2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (boxes[j][0] < boxes[i][0] && boxes[j][1] < boxes[i][1] && boxes[j][2] < boxes[i][2]) {
                dp[i] = max(dp[i], dp[j] + boxes[i][2]);
                res = max(res, dp[i]);
            }
    }
    cout << res << endl;


	return 0;
}