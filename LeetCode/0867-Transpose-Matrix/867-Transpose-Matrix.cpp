/*
LeetCode 867: Transpose Matrix
Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, 
switching the matrix's row and column indices.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
1 <= m * n <= 10^5
-10^9 <= matrix[i][j] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        int m = 1;
        if (row == col) {
            for (; m <= matrix.size(); ++m) {
                for (int i = 0; i < m; ++i) {
                    swap(matrix[m - 1][i], matrix[i][m - 1]);
                }
            }
        } else {
            vector<vector<int>> res(col, vector<int>(row));
            for (int i = 0; i < col; i++)
                for (int j = 0; j < row; j++)
                    res[i][j] = matrix[j][i];
            return res;
        }
        return matrix;
    }
};
int main() {

    return 0;
}