/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0056-Merge-Intervals/56.cpp
 * @Description: 
 */
/*
LeetCode 56: Merge Intervals
@Description:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Constraints:
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：排序即可
不用将情况复杂化
1.新区间interval[i]的左右值分别为Left, Right
    - 若res.back()[1] < Left，将interval[i]加入res数组
    - 若res.back()[1] >= Left，不添加入res数组，更新res.back()[1]即可 

*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& nums1, const vector<int>& nums2) {
            return (nums1[0] < nums2[0]) || ((nums1[0] == nums2[0]) && (nums1[1] < nums2[1]));
        });
        vector<vector<int>> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            vector<int> elem(intervals[i]);
            if (res.empty() || res.back()[1] < elem[0])
                res.emplace_back(elem);
            else
                res.back()[1] = max(res.back()[1], elem[1]);

        }
        return res;
    }
};
int main() {


    return 0;
}