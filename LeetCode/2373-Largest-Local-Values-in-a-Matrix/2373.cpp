#include <bits/stdc++.h>
using namespace std;
/*
思路：直接模拟 MaxPooling
*/
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, 0));
        for (int i = 0; i + 2 < n; ++i) {
            for (int j = 0; j + 2 < n; ++j) {
                for (int mazeI = 0; mazeI < 3; ++mazeI)
                    for (int mazeJ = 0; mazeJ < 3; ++mazeJ)
                        maxLocal[i][j] = max(maxLocal[i][j], grid[i + mazeI][j + mazeJ]);
            }
        }
        return maxLocal;
    }
};
int main() {
    Solution ss;



    return 0;
}