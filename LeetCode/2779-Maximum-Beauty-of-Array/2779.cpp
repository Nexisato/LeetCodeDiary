#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        const int n = nums.size();
        int m = *max_element(nums.begin(), nums.end());
        vector<int> diff(m + 2, 0);
        for (auto&& num : nums) {
            // 左区间最小可到达的点
            int left = max(0, num - k);
            // 右区间最小不可到达的点
            int right = min(m + 1, num + k + 1);
            ++diff[left];
            --diff[right];  // 这是因为 right 是不可到达的点，所以要 -1
        }
        int res = 0;
        int sum = 0;
        for (auto&& d : diff) {
            sum += d;
            res = max(res, sum);
        }
        return res;
    }

    int maximumBeauty_bs(vector<int>& nums, int k) {
        const int n = nums.size();
        int res = INT32_MIN;
        namespace ranges = std::ranges; // C++20
        ranges::sort(nums);
        for (int l = 0, r = 0; r < n; ++r) {
            while (nums[r] - nums[l] >  2 * k) {
                ++l;
            }
            res = max(res, r - l + 1);
        }


        return res;
    }
};

TEST(Solution, maximumBeauty) {
    Solution solution;

    vector<int> nums1 = {4, 6, 1, 2};
    EXPECT_EQ(solution.maximumBeauty_bs(nums1, 2), 3);

    vector<int> nums2 = {1, 1, 1, 1};
    EXPECT_EQ(solution.maximumBeauty_bs(nums2, 10), 4);

}

int main() {
    // g++ 2779.cpp -lgtest -lgtest_main -pthread -o 2779
    // to run the test: ./2779
    testing::InitGoogleTest();


    return RUN_ALL_TESTS();
}