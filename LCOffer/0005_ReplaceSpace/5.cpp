/*
LCOffer 5: Replace Space
@Description:
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。 
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (auto& c: s) {
            if (c == ' ')
                res += "%20";
            else
                res += c;
        }
        return res;
    }
    string replaceSpace_expand_s(string s) {
        int count = 0;
        int sOldL = s.length();
        for (int i = 0; i < sOldL; ++i)
            if (s[i] == ' ')
                ++count;
        s.resize(s.size() + 2 * count);
        int sNewL = s.size();
        for (int i = sNewL - 1, j = sOldL - 1; j < i; --i, --j) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
int main() {

    return 0;
}