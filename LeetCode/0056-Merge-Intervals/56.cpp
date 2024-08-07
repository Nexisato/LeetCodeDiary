/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0056-Merge-Intervals/56.cpp
 * @Description:
 */
/*
LeetCode 56: Merge Intervals
@Description:
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping
intervals, and return an array of the non-overlapping intervals that cover all the
intervals in the input.

Constraints:
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4
*/
#include <iostream>
#include <vector>
#include <bitset>
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
		sort(intervals.begin(), intervals.end(),
		     [](const vector<int>& nums1, const vector<int>& nums2) {
			     return (nums1[0] < nums2[0]) ||
			            ((nums1[0] == nums2[0]) && (nums1[1] < nums2[1]));
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
	// const 可能会触发reference binding error，直接 sort 就行
	vector<vector<int>> merge_tmp2(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        const int n = intervals.size();
        int l = intervals[0][0], r = -1;
        for (int i = 0, j = 0; i < n;) {
            l = intervals[i][0];
            r = intervals[i][1];
            j = i + 1;
            while (j < n && intervals[j][0] <= r) {
                r = max(r, intervals[j][1]);
                ++j;
            }
            res.push_back({l, r});
            i = j;
        }


        return res;
    }


	
	vector<vector<int>> merge_bitset(vector<vector<int>>& intervals) {
        const int MAX_SIZE = 10000; // 假设区间最大值为 10000
        bitset<MAX_SIZE * 2 + 2> bitSet;
        int max_val = 0;

        for (const auto& interval : intervals) {
            int start = interval[0] * 2;
            int end = interval[1] * 2 + 1;	// 确保 左右端点一样的情况下也可以被考虑到
            for (int i = start; i < end; ++i) {
                bitSet.set(i);
            }
            max_val = std::max(max_val, end);
        }

        vector<vector<int>> result;
		// 注意这里从 -1 开始，保证第一个区间的左端点为 0
        int index = -1;
        while (index < max_val) {
            int start = bitSet._Find_next(index);
            if (start == -1) break;
            int end = start;
			while (bitSet[end]) ++end;
            result.push_back({start / 2, (end - 1) / 2});
            index = end;
        }

        return result;
	}
};
int main() { 
	Solution *ss = new Solution();
	vector<vector<int>> intervals = {{0, 0}, {1, 4}};

	vector<vector<int>> res = ss->merge_bitset(intervals);

	
	return 0; 
	
}