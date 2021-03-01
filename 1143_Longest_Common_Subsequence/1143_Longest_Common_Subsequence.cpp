/*
Description:
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string  with some characters
(can be none) deleted without changing the relative order of the remaining 
characters. 
(eg, "ace" is a subsequence of "abcde" while "aec" is not). 
A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Constraints:
1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.
*/
#include<bits/stdc++.h>
using namespace std;

//思路： DP
//按照两个字符串的大小建立最长公共子序列矩阵，根据DP递推式，直接返回矩阵最大值
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int L[text1.size()+1][text2.size()+1];
        for(int i=0;i<text1.size()+1;++i)
            L[i][0]=0;
        for(int j=0;j<text2.size()+1;++j)
            L[0][j]=0;
        for(int i=1;i<=text1.size();i++)
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]) 
                    L[i][j]=L[i-1][j-1]+1;
                else
                    L[i][j]=max(L[i-1][j],L[i][j-1]);
                
            }
        return L[text1.size()][text2.size()];
    }
    int longsestCommonSubsequence (string text1, string text2) {
        
    }
};

int main(){
    string text1="xyxxzxyzxy";
    string text2="zxzyyzxxyxxz";
    Solution ss;
    cout<<ss.longestCommonSubsequence(text1,text2)<<endl;
    return 0;
}