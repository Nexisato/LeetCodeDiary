/*
Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order.

Ex:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    //思路：1.暴力法（超时，不推荐） 2.双指针法 3.hash表（强烈推荐)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            unordered_map<int,int>::iterator it = table.find(target - nums[i]);
            if(it != table.end()){
                return {i, it->second};
            }
            table[nums[i]] = i;
        }
        return {};
    }
      void Print(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it+=1){
            cout<<*(it)<<endl;
        }
    }
};
/*
思路：双指针返回数值（不是元素索引）
1. 先对数组从小到大排序
2. 双指针遍历数组，对首尾元素求和，依据大小调整双指针位置
*/
class Solution_fastPtr {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            int lVal = nums[l];
            int rVal = nums[r];
            if (sum < target)
                while(l < r && nums[l] == lVal)
                    l++;
            else if (sum > target)
                while (l < r && nums[r] == rVal)
                    r--;
            else 
                return {nums[l], nums[r]};
        }
        return {};
    }

};
int main()
{
    vector<int> nums={3, 2, 4};
    Solution_fastPtr ss;
    vector<int> ans=ss.twoSum(nums, 6);
    return 0;
}