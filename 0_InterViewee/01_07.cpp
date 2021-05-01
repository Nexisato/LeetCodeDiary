/*
面试题01.07: Rotate Matrx LCCI
Given an image represented by an N x N matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 转置
2. 按行翻转
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) 
            for (int j = i; j < n; ++j) 
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
int main() {




    return 0;
}