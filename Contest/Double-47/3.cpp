/*
LeetCode 5682: Sum of Beauty of All Substrings
@Description:
The beauty of a string is the difference in frequencies 
between the most frequent and least frequent characters.

For example, the beauty of "abaacc" is 3 - 1 = 2.
Given a string s, return the sum of beauty of all of its substrings.

Constraints:
1 <= s.length <= 500
s consists of only lowercase English letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
枚举子串起点，用字母表table维护不同字符的出现频次
*/
class Solution {
private:
    int countBeauty(int *table) {
        int maxCount = 0, minCount = 500;
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            if (table[i] != 0) {
                maxCount = max(maxCount, table[i]);
                minCount = min(minCount, table[i]);
            }
        }
        res = maxCount - minCount;
        return res;
    }
public:
    int beautySum(string s) {
        int n = s.length();
        if (n == 1) return 0;
        int table[26] = {0};
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            table[s[i] - 'a']++;
            for (int j = i + 1; j < n; ++j) {
                table[s[j] - 'a']++;
                res += countBeauty(table);
            }
            memset(table, 0, sizeof(table));
        }
        return res;
    }
};
int main() {

    return 0;
}