/*
LeetCode 1738: Find Kth Largest XOR Coordinate Value
@Description:
You are given a 2D matrix of size m x n, consisting of non-negative integers. 
You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] 
where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 10^6
1 <= k <= m * n
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：异或前缀和 + 最小堆 
*/
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> xorSum(m + 1, (vector<int>(n + 1, 0)));
        xorSum[1][1] = matrix[0][0];
        vector<int> res;
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                xorSum[i][j] = matrix[i - 1][j -1] ^ xorSum[i][j - 1] 
                ^ xorSum[i - 1][j] ^ xorSum[i - 1][j - 1];
                res.emplace_back(xorSum[i][j]);
            }
        priority_queue<int, vector<int>, less<int>> minHeap;
        int N = res.size();
        for (int i = 0; i < N; ++i) {
            if (minHeap.size() < k) {
                minHeap.push(res[i]);
                continue;
            }
            if (res[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(res[i]);
            }
        }
        return minHeap.top();
    }
};
int main() {

    return 0;
}