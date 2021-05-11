/*
LeetCode 542: 0-1 Matrix
@Description:
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 10^4
1 <= m * n <= 10^4
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：从0像素出发，而不是从1像素
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        vector<bool> visited(n * m, false);
        int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    visited[i * n + j] = true;
                }
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();
                if (mat[r][c] == 1)
                    res[r][c] = step;
                for (int k = 0; k < 4; ++k) {
                    int nr = r + d[k][0];
                    int nc = c + d[k][1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr * n + nc])
                        continue;
                    q.emplace(nr, nc);
                    visited[nr * n + nc] = true;
                }
            }
            ++step;
        }
        return res;
    }
};
int main() {
    vector<vector<int>> mat{
      {0, 0, 0},
      {0, 1, 0},
      {1, 1, 1}  
    };
    Solution ss;
    vector<vector<int>> res;
    res = ss.updateMatrix(mat);
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[0].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}