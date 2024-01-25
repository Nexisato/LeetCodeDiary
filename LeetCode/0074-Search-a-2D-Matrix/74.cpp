/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0074-Search-a-2D-Matrix/74.cpp
 * @Description: 
 */
/*
LeetCode 74: Search a 2D Matrix
@Description:
Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-10^4 <= matrix[i][j], target <= 10^4
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：二分查找
先对第一列二分搜索，再对对应行二分搜索
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, rowMid = (up + down) / 2, targetRow = 0;
        while (up <= down) {
            if (rowMid == m - 1 && target >= matrix[rowMid][0]) {
                targetRow = m - 1;
                break;
            }
            else if (target >= matrix[rowMid][0] && 
                target < matrix[rowMid + 1][0]) {
                targetRow = rowMid;
                break;
            }
            else if (target < matrix[rowMid][0])
                down = rowMid - 1;
            else if (target > matrix[rowMid][0])
                up = rowMid + 1;
            rowMid = up + (down - up) / 2;
        }
        int left = 0, right = n - 1, midCol = (left + right) / 2;
        while (left <= right) {
            if (target == matrix[targetRow][midCol])
                return true;
            else if (target > matrix[targetRow][midCol])
                left = midCol + 1;
            else if (target < matrix[targetRow][midCol])
                right = midCol - 1;
            midCol = left + (right - left) / 2;
        }
        return false;
    }
    //将不同行矩阵拼接成一行，可以直接使用一次二分
    bool searchMatrix_one_Time(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1, mid = 0;
        int row = 0, col = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            row = mid / n;
            col = mid % n;
            if (target == matrix[row][col])
                return true;
            else if (target < matrix[row][col])
                r = mid - 1;
            else if (target > matrix[row][col])
                l = mid + 1;
        }
        return false;
    }
};

int main() {

    return 0;
}