/**
 * @file redbook_2.cpp
 * @Question: 小红的回文串
 * @Description:
小红有一个字符串，她可以进行以下操作:
-拆分。把’w'拆成2个’v'，’m’拆成 2个'n’。
-轴堆成。把’b’轴对称成’d’，’p’轴对称成’q’，反之亦然。
-翻转。把’b’反转成’q’，把’d’翻转成’p’，把’n’翻转成’u’

经过若干次操作，小红想知道这个字符串能不能变成回文串。

输入描述：
第一行输入一个整数 T(1<=T<=10^4)表示询问次数
接下来T行，每行输入一个字符串表示询问。
所有字符串长度之和不超过 10^5。

输出描述：
输出T行，每行输出"YES”或“NO”表示是否可以变成回文串。
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief:
 * 不要搜索！
 * 直接对字符串进行变形，然后判断是否为回文串
 * b; d; q; p 全部替换为 b
 * w 全部变成 v v
 * m 全部变成 u u
 * n 全部变成 u
 */

bool isPalindrome(string& s) {
    int n = s.size();
    string s_transfer = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'b' || s[i] == 'd' || s[i] == 'q' || s[i] == 'p')
            s_transfer += 'b';
        else if (s[i] == 'w')
            s_transfer += "vv";
        else if (s[i] == 'm')
            s_transfer += "uu";
        else if (s[i] == 'n')
            s_transfer += 'u';
        else
            s_transfer += s[i];
    }
    int n_transfer = s_transfer.size();
    for (int l = 0, r = n_transfer - 1; l < r; ++l, --r)
        if (s_transfer[l] != s_transfer[r]) return false;
    return true;
}

int main() {
    int queryTime;
    cin >> queryTime;
    string answer[queryTime];
    for (int i = 0; i < queryTime; ++i) {
        string s;
        cin >> s;
        if (isPalindrome(s))
            answer[i] = "YES";
        else
            answer[i] = "NO";
    }
    for (const auto& ans : answer) cout << ans << endl;

    return 0;
}