/*
 * @Date: 2024-01-16 11:46:12
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0228_Summary_Ranges/228.cpp
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> res;
        if (n == 0) return res;
        int left = 0, right = 0;
        while (right < n) {
            // 连续数字不断移动指针
            while (right + 1 < n && nums[right + 1] == nums[right] + 1) 
                ++right;
            if (left == right) 
                res.push_back(to_string(nums[left]));
            else 
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            ++right;
            left = right;
        }
        return res;
    }
};
int main() {

    return 0;
}