#include <bits/stdc++.h>
using namespace std;

/*
思路：回溯算法

*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        int subSum = sum / k, n = nums.size();
        if (nums[0] > subSum)
            return false;
        vector<int> bucket(k, 0);
        auto dfs = [&, end = nums.cend()](auto&& dfs, auto&& it) {
            if (it == end)
                return true;
            for (size_t i = 0; i < k; ++i) {
                if (bucket[i] + *it > subSum || (i && bucket[i - 1] == bucket[i]))
                    continue;
                bucket[i] += *it;
                if (dfs(dfs, it + 1))
                    return true;
                bucket[i] -= *it;
            }
            return false;
        };
        return dfs(dfs, nums.cbegin());

        
    }
};
int main() {
    vector<int> nums = {2,2,2,2,3,4,5};
    int k = 4;
    Solution *ss;
    bool res = ss->canPartitionKSubsets(nums, k);
    cout << res << endl;


    return 0;
}