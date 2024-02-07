/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0028-strStr/28-strStr.cpp
 * @Description: 
 */
/*
Description:
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Clarification:
What should we return when needle is an empty string? This is a great question
to ask during an interview. For the purpose of this problem, we will return 0
when needle is an empty string. This is consistent to C's strstr() and
Java's indexOf().

Constraints:
0 <= haystack.length, needle.length <= 5 * 10^4
haystack and needle consist of only lower-case English characters.

*/
#include <iostream>
#include <vector>
using namespace std;

// 思路：模式匹配，可用KMP :先构建next数组，再利用next数组做匹配
class Solution {
private:
    // 构建next数组，记录【模式串】最长相同前后缀子串长度
    void getNext(vector<int> &next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.length(); ++i) {
            while (j >= 0 && s[i] != s[j + 1])
                j = next[j];
            if (s[i] == s[j + 1])
                ++j;
            next[i] = j;
        }
    }

public:
    // 利用模式串的next数组匹配文本串
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        int j = -1;
        vector<int> next(needle.length(), 0);
        getNext(next, needle);
        for (int i = 0; i < haystack.size(); ++i) {
            while (j >= 0 && haystack[i] != needle[j + 1])
                j = next[j];
            if (haystack[i] == needle[j + 1])
                ++j;
            if (j == needle.size() - 1)
                return i - j;
        }
        return -1;
    }
};

int main() {
    Solution ss;
    string haystack = "a";
    string needle = "a";
    cout << ss.strStr(haystack, needle);
    return 0;
}