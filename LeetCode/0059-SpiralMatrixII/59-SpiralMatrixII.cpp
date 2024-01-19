/*
Leetcode :59
Description:
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order.

Constraints:
1<=n<=20
*/
#include<bits/stdc++.h>
using namespace std;
/*
思路：

*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) { 
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        int bnd = 0;
        while (n != 0) {
            for (int i = bnd; i < n; ++i) 
                res[bnd][i] = num++;
            for (int i = bnd + 1; i < n; ++i) 
                res[i][n - 1] = num++;
            for (int i = n - 2; i >= bnd; --i)
                res[n - 1][i] = num++;
            for (int i = n - 2; i > bnd; --i)
                res[i][bnd] = num++;
            n--;
            bnd++;
        }
        return res;
    }
};
int main() {
    Solution ss;
    int n = 4;
    vector<vector<int>> matrix = ss.generateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}