/*
LeetCode: 15 3Sum
Description:
Given an array nums of n integers, are there elements a, b, c in nums 
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

Constraints:
0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 从头遍历nums
2. 找到 target 值为 0-nums[i] 的twoSum序列
    · 双指针法 (效率较低，时间复杂度O(n^2))
    · 哈希表（暂定；会出现重复元素）
3. 将nums[i]合并到twoSum序列中
*/
class Solution {
private:
    vector<vector<int>> twoSum_1(vector<int>& nums, int start, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int l = start, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            int lVal = nums[l], rVal = nums[r];
            if (sum < target)
                while(l < r && nums[l] == lVal)
                    l++;
            else if (sum > target)
                while (l < r && nums[r] == rVal)
                    r--;
            else {
                res.push_back({nums[l], nums[r]});
                while(l < r && nums[l] == lVal)
                    l++;
                while (l < r && nums[r] == rVal)
                    r--;
            }
        }
        return res;
    }
     vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> res;
        unordered_map<int, int> table;
        for (int i = start; i < nums.size(); i++) {
            auto it = table.find(target - nums[i]);
            if (it != table.end()) 
                res.push_back({nums[i], nums[it->second]});
            table[nums[i]] = i; 
        }
        return res;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            vector<vector<int>> pairs = twoSum(nums, i + 1, target);
            for (vector<int>& pair : pairs) {
                pair.push_back(nums[i]);
                res.push_back(pair);
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return res;
    }
};

class Solution_new {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) //sorted, can't added to zero
                return res;
            
            if (i > 0 && nums[i] == nums[i - 1]) //先去重就放在前面这
                continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    //找到答案后移动指针
                    right--;
                    left++;
                }
            }
        }



        return res;
    }
};
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    Solution ss;
    vector<vector<int>> res = ss.threeSum(nums);
    for (vector<int>& tmp : res) {
        for (int i = 0; i < tmp.size(); i++)
            cout << tmp[i] << " ";
        cout << "\n";
    }
    return 0;
}