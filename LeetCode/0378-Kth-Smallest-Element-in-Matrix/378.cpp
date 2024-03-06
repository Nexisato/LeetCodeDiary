/*
 * @Date: 2024-03-06 20:30:26
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0378-Kth-Smallest-Element-in-Matrix/378.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <queue>
using namespace std;

class Solution {
public:
    // 二分，思路比较巧，
    // 如果 小于等于 mid 的元素 数量 大于等于 k ，说明 第 k 小的元素小于等于 mid
    // 如果 小于等于 mid 的元素 数量 小于 k，那么说明 第 k 小的元素大于 mid
    // 算数量也是个技巧，从左下角到右上角遍历, 走列，计算行
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        auto checkNum = [&](int mid) -> bool {
            int i = n - 1, j = 0;
            int num = 0;
            while (i >= 0 && j < n) {
                if (matrix[i][j] <= mid) {
                    num += (i + 1); // 按照列计算
                    ++j;
                } else {
                    --i;
                }
            }
            return num >= k;
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (checkNum(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            
        }
        return l;
    }
    int kthSmallest_heap(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int _val, int _x, int _y) : val(_val), x(_x), y(_y) {}
            bool operator>(const point& other) const {
                return this->val > other.val;
            }
        };
        const int n = matrix.size();
        priority_queue<point, vector<point>, greater<point>> minHeap;
        for (int i = 0; i < n; ++i)
            minHeap.push(point(matrix[i][0], i, 0));
        
        // 弹出 k-1 个小的元素即可得到第 k 小的元素
        for (int i = 0; i < k - 1; ++i) {
            auto p = minHeap.top();
            minHeap.pop();
            if (p.y != n - 1)
                minHeap.push(point(matrix[p.x][p.y + 1], p.x, p.y + 1));
        }
        return minHeap.top().val;

    }
};
int main() {



    return 0;
}