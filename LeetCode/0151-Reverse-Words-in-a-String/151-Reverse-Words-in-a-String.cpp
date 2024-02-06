/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0151-Reverse-Words-in-a-String/151-Reverse-Words-in-a-String.cpp
 * @Description: 
 */
/*
LeetCode: 151 Reverse Words in a String
Description:
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. 
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.

Constraints:
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.
 
Follow up:
Could you solve it in-place with O(1) extra space?
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
思路：
1. 从后向前迭代访问，若遇到空格则跳过，直到非空格
2. 遍历到单词首字母的前一个位置，记录此刻下标
3. 再次遍历此单词，将该单词记录到res字符串中
4. 回到记录下标位置继续从后向前遍历
5. 移除res字符串末尾的空格
*/
class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0) return "";
        string res = "";
        int j = s.length() - 1;
        bool isProcessed = false;
        while (j >= 0) {
            if (s[j] == ' ') {
                j--;
                continue;
            }
            // j必须放在前面
            while (j >= 0 && s[j] != ' ') 
                j--;
            int pos = j;
            isProcessed = true;
            j++;
            while (s[j] != ' ' && j < s.length()) {
                res += s[j];
                j++;
            }
            j = pos;
            res += ' ';
        }
        if (isProcessed)
            res.erase(res.length() - 1, 1);
        return res;
    }

    string reverseWords_no_extra(string s) {
        auto reverse = [&](int l, int r) {
            for (int i = l, j = r; i < j; ++i, --j) 
                swap(s[i], s[j]);
        };
        auto removeExtraSpaces = [&]() {
            int slow = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != ' ') {
                    if (slow != 0) s[slow++] += ' ';
                    while (i < s.size() && s[i] != ' ')
                        s[slow++] = s[i++];
                }
            }
            s.resize(slow);
        };
        removeExtraSpaces();
        reverse(0, s.length() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
int main() {
    string s = "  ";
    Solution ss;
    cout << ss.reverseWords(s) << endl;
    return 0;
}