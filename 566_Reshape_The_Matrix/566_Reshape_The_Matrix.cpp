/*
LeetCode 566: Reshape The Matrix
@Description:
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into 
a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers 
r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix 
in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, 
output the new reshaped matrix; Otherwise, output the original matrix.

Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：直接模拟
遍历nums矩阵，取到c个元素后记录并清空，再重新取值
*/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m * n != r * c) return nums;
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp.emplace_back(nums[i][j]);
                if (tmp.size() == c) {
                    res.emplace_back(tmp);
                    tmp.clear();
                }
            }
        }
        return res;
    }
};
int main() {

    return 0;
}