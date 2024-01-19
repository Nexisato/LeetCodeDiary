#include <bits/stdc++.h>
using namespace std;
/*
思路：
- 不要被countUniqueChars所迷惑
- 考虑对于单个字符来说，可以计算贡献值
- 对于某个字符，找到它前一个相同字符的位置和后一个相同字符的位置，计算该字符在这子串间可以出现多少次
*/
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> lastIndex(26, -1), curIndex(26, -1);
        int res = 0, n = s.length();

        for (int i = 0; i < n; ++i) {
            int letter = s[i] - 'A';

            if (curIndex[letter] > -1) {
                res += (i - curIndex[letter]) * (curIndex[letter] - lastIndex[letter]);
            }

            lastIndex[letter] = curIndex[letter];
            curIndex[letter] = i;
        }
        //最后是 next 字符
        for (int letter = 0; letter < 26; ++letter)
            if (curIndex[letter] > - 1)
                res += (curIndex[letter] - lastIndex[letter]) * (n - curIndex[letter]);



        return res;
    }
    
    /*
    int uniqueLetterString(string s) {
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                res += countUniqueChars(s.substr(i, j - i));

        return res;
    }

    int countUniqueChars(string s) {
        vector<char> table(26, 0);
        for (const auto& a : s) {
            ++table[a - 'A'];
        }
        int sum = 0;
        for (const auto& count : table)
            if (count == 1)
                ++sum;
        return sum;
    }*/
};

int main() {

    return 0;
}