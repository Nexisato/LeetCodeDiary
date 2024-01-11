/*
 * @Date: 2024-01-08 15:01:32
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0057_Insert_Interval/57.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 *  分三段遍历
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        const int n = intervals.size();
        int idx = 0;
        // 左侧，不重叠
        while (idx < n && intervals[idx][1] < newInterval[0]) {
            res.push_back(intervals[idx++]);
        }

        // 重叠部分更新总区间后再加入到 res 中
        while (idx < n && intervals[idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[idx][0]);
            newInterval[1] = max(newInterval[1], intervals[idx][1]);
            idx++;
        }
        res.push_back(newInterval);

        // 右侧，不重叠
        while (idx < n && intervals[idx][0] > newInterval[1]) {
            res.push_back(intervals[idx++]);
        }

        return res;
    }
};
int main() {

    return 0;
}