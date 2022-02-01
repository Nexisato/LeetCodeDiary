/*
LeetCode 1763: Longest Nice Substring
@Description:

A string s is nice if, for every letter of the alphabet that s contains, 
it appears both in uppercase and lowercase. For example, 
"abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. 
However, "abA" is not because 'b' appears, but 'B' does not.

Given a string s, return the longest substring of s that is nice. 
If there are multiple, return the substring of the earliest occurrence. 
If there are none, return an empty string.

Constraints:
1 <= s.length <= 100
s consists of uppercase and lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：位标记 + 滑动窗口
为什么要双重循环呢，要找到最长的 substring
以起始点开始扫描的话，只可以找到以此开始的nice substring
*/
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        int maxLen = 0, maxPos = 0;
        int lower = 0, upper = 0;
        for (int j = 0; j < n; ++j) {
            lower = 0;
            upper= 0;
            for (int i = j; i < n; ++i) {
                if (islower(s[i])) {
                    lower |= (1 << (s[i] - 'a'));
                } else if (isupper(s[i])) {
                    upper |= (1 << (s[i] - 'A'));
                }
                if (lower == upper && i - j + 1 > maxLen) {
                    maxLen = i - j + 1;
                    maxPos = j;
                }

            }
        }
        return s.substr(maxPos, maxLen);
        
    }
};
int main() {


    return 0;
}