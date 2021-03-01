/*
LeetCode 832: Flip Image
@Description:
Given a binary matrix A, we want to flip the image horizontally, then invert it, 
and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  
For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. 
For example, inverting [0, 1, 1] results in [1, 0, 0].

Notes:
1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：直接模拟即可
由于翻转后进行取反操作，因此仅当 A[i][left] == A[i][right]时，取反才会有效
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            int left = 0, right = row.size() - 1;
            while (left < right) {
                if (row[left] == row[right]) {
                row[left] ^= 1;
                row[right] ^= 1;
                }
                ++left;
                --right;
            }
            if (left == right)
                row[left] ^= 1;
        }
        return A;
    }
};
int main() {

    return 0;
}