/*
LeetCode 643: Maximum Average Subarray I
@Description:
Given an array consisting of n integers, find the contiguous subarray of 
given length k that has the maximum average value. 
And you need to output the maximum average value.

Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
滑动窗口速刷
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 1) return (double) nums[0];
        double res = 0, sum = 0, maxSum = INT32_MIN;
        int left = 0, right = 0;
        while (right < nums.size()) {
            sum += nums[right]; 
            ++right;
            if (right >= k) {
                maxSum = max(maxSum, sum);
                sum -= nums[left++];
            }
        }
        return (double) maxSum / k;
    }
};
int main() {
    vector<int> nums = {8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};
    int k = 93;
    Solution ss;
    double res;
    cout << ss.findMaxAverage(nums, k) << endl;
    return 0;
}