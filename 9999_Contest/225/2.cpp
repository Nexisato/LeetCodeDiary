/*
5662. 满足三条件之一需改变的最少字符数 
给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。

操作的最终目标是满足下列三个条件 之一 ：
a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。

提示：
1 <= a.length, b.length <= 10^5
a 和 b 只由小写字母组成
*/
#include <bits/stdc++.h>
using namespace std;


/*
思路：
1. 条件一与条件二等价，交换数组即可
2. 考虑条件三：只需要在两个字符串中总计出现次数最多的那个字符，然后将剩余字符全部替换为它
3. 考虑条件一二，令A中所有字符都小于c, B中所有字符都大于c，枚举c找出最优解即可
*/
class Solution {
public:
    int minCharacters(string a, string b) {
        int m = a.length(), n = b.length();
        vector<int> ca(26), cb(26);
        for (char c : a)
            ca[c - 'a']++;
        for (char c : b)
            cb[c - 'a']++;
        int ans = n + m;
        
        for (int i = 0; i < 26; ++i)
            ans = min(ans, n + m - ca[i] - cb[i]);

        auto make_smaller = [&](vector<int> &a, vector<int> &b) {
            for (int i = 1; i < 26; ++i) {
                int tmp = 0;
                for (int j = i; j < 26 ; ++j) 
                    tmp += a[j];
                for (int j = 0; j < i; ++j) 
                    tmp += b[j];
                ans = min(ans, tmp);
            }
        };

        make_smaller(ca, cb);
        make_smaller(cb, ca);

        return ans;
    }
};
int main() {
    string a = "aba";
    string b = "caa";
    Solution ss;
    cout << ss.minCharacters(a, b) << endl;
    return 0;
}