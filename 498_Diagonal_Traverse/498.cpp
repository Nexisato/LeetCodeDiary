/*
LeetCode 498: Diagonal Traverse
@Description:
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
-10^5 <= mat[i][j] <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
/*
 1  2  3  4  9
 5  6  7  8  9
 9 10 11 12  6
13 14 15 16  1

先从右上角遍历，再按照奇数条对角线顺序翻转

*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for (int i = 0; i < m * n; ++i) {
            vector<int> tmp;        
            //RightUp to LeftBottom
            int r = (i < n) ? 0 : (i - n + 1);
            int c = (i < n) ? i : n - 1;
            while (r < m && c > -1) {
                tmp.emplace_back(mat[r][c]);
                ++r;
                --c;
            }
            //第奇数条对角线，对应i为偶数
            if (i % 2 == 0)
                reverse(tmp.begin(), tmp.end());

            for (auto& num : tmp)
                res.emplace_back(num);
        }
        return res;
    }
};
int main() {


    return 0;
}