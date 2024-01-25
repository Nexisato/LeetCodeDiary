/*
 * @Date: 2024-01-25 10:44:44
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0219-Contains-Duplicate-II/219.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (table.count(nums[i]) && i - table[nums[i]] <= k) {
                return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};
int main() {


    return 0;
}