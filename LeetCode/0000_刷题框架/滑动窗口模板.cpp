#include <bits/stdc++.h>
using namespace std;
/*滑动窗口框架*/
void silidingWindows(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) 
        need[c]++;
    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        //移入窗口
        char c = s[right];
        right++;

        //更新
        /*
            code
        */

       //判断左侧窗口是否需要收缩
       while (window needs shrink) {
           //d是移出窗口的字符
           char d = s[left];
           left++;

           //更新
           /*
                code
           */
       }
    }
}
int main() {

    return 0;
}