/*
LeetCode 557: Remove Words in a String 
Given a string s, reverse the order of characters in each word within 
a sentence while still preserving whitespace and initial word order.

Constraints:
1 <= s.length <= 5 * 10^4
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：分开res和tmp字符串
tmp字符串用来记录单词
res字符串添加空格后，再拼接翻转后的单词
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string res = "", tmp = "";
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ' && !tmp.empty()) {
                reverse(tmp.begin(), tmp.end());
                res += tmp;
                res += ' ';
                tmp.clear();
                continue;
            }
            tmp += s[i];
        }
        if (!tmp.empty()) {
            reverse(tmp.begin(), tmp.end());
            res += tmp;
        }
        return res;
    }
};
int main() {


    return 0;
}