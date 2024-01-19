/*
LeetCode 1208: Get Equal Substrings within Budget
@Description:
You are given two strings s and t of the same length. You want to change s to t. 
Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is, 
the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.

Return the maximum length of a substring of s that can be changed to be the same as 
the corresponding substring of t with a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Constraints:
1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
1. 遍历字符串，若对应的字符差值在maxCost之内，增加窗口，否则减小窗口
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0, sum = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            sum += abs(s[right] - t[right]);
            right++;
            if (sum > maxCost) {
                sum -= abs(s[left] - t[left]);
                ++left;
            }
            res = (res < right - left) ? (right - left) : res;
        }
        return res;
    }
};
int main() {
    string s = "krrgw";
    string t = "zjxss";
    int maxCost = 19;
    Solution ss;
    cout << ss.equalSubstring(s, t, maxCost) << endl;

    return 0;
}