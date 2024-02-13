/*
 * @Date: 2024-02-13 09:51:03
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0149-Max-Points-in-a-Line/149.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int res = 0;
        unordered_map<double, int> record;
        for (int i = 0; i < n - 1; ++i) {
            // 重置哈希表，使用 move 语义，减少内存开销
            record = std::move(unordered_map<double, int>());
            for (int j = i + 1; j < n; ++j) {
                double dx = points[j][0] - points[i][0];
                double dy = points[j][1] - points[i][1];
                double k = (dx == 0) ? numeric_limits<double>::max() : static_cast<double>(dy / dx);
                ++record[k];
            }
            for (auto& [_, count] : record) {
                res = max(res, count + 1);
            }

        }

        return res;
    }

};

int main() {
    return 0;
}