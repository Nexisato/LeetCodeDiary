#include <iostream>
#include <vector>
#include <limits>
using namespace std;


// 原地 hash，预期 nums[i] = i + 1;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        int res = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            // 注意这个循环
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1) {
                res = i + 1;
                break;
            }
        return res == numeric_limits<int>::max() ? n + 1 : res;
    }
};


int main() {


    return 0;
}