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
};
int main() {

    return 0;
}