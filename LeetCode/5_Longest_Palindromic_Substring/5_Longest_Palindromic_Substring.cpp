/*
LeetCode: 5 Longest Palindromic Substring
Description:
Given a string s, return the longest palindromic substring in s.

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/
#include <bits/stdc++.h>
using namespace std;

/*
思路：
1. 双指针法，由字符串中间向两边扩散
若中点有两个，与中点有一个的放在一起进行扩展即可
*/
class Solution {
private:
    int left = 0;
    int right = 0;
    int maxLength = 0;
public:
    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            traverse(s, i, i);
            traverse(s, i, i+ 1);
        }
        return s.substr(left, maxLength);
    }
    void traverse(const string& s, int i, int j) {
        while (0 <= i && j < s.length() && s[i] == s[j]) {
            if ((j - i + 1) > maxLength) {
                left = i;
                right = j;
                maxLength = j - i + 1;
            }
            i--;
            j++;
        }
    }

};

int main() {
    string s = "babad";
    Solution ss;
    cout << ss.longestPalindrome(s) <<endl;
    return 0;
}