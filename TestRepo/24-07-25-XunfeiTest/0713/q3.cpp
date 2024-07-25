#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

// 这里需要使用到一个状态机转移的思路

const int MAX_COUNT = 20001;
const int INF = 1e+6;


// not completed
int main() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    int max_val = - 1;
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        max_val = std::max(max_val, nums[i]);
    }








    return 0;
}