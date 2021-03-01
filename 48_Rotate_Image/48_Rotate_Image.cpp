/*
Description:
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    //思路：先转置，再逆序
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
            for(int j=i;j<matrix.size();j++)
                swap(matrix[i][j],matrix[j][i]);
        for(int i=0;i<matrix.size();i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }         
    
};

int main(){
    vector<vector<int>> matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution ss;
    ss.rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix.size();j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }
    

    return 0;
}