/*
Description: LeetCode 169
Given an array of size n,
find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 思路：MooreVote法
// 时间复杂度:O(n) 空间复杂度:O(1)
class Solution {
	int MooreVote(vector<int>& nums) {
		int cand = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (cand == nums[i])
				++count;
			else if (--count == 0) {
				cand = nums[i];
				count = 1;
			}
		}
		return cand;
	}

public:
	int majorityElement(vector<int>& nums) { return MooreVote(nums); }
};
int main() { return 0; }