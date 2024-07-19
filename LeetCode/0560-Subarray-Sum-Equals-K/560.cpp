#include <iostream>
#include <vector>
#include <unordered_map>
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        int res = 0;
        unordered_map<int, int> table;
        int sum = 0;
        table[0] = 1;
        for (auto&& num : nums) {
            sum += num;
            if (table.contains(sum - k)) {
                res += table[sum - k];
            } 
            ++table[sum];
        }


        return res;
    }
};


TEST(Solution, case1) {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    EXPECT_EQ(solution.subarraySum(nums, k), 2);
}

TEST(Solution, case2) {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    EXPECT_EQ(solution.subarraySum(nums, k), 2);
}

int main() {
    testing::InitGoogleTest();



    return RUN_ALL_TESTS();
}