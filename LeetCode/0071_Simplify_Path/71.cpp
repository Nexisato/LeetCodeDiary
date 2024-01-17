/*
 * @Date: 2024-01-16 11:53:28
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0071_Simplify_Path/71.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        int idx = 0;
        const int n = path.length();
        vector<string> paths;
        while (idx < n) {
            while (idx < n && path[idx] == '/')
                ++idx;
            if (idx == n)
                break;
            int start = idx, end = idx;
            if (path[end] == '.') {
                // .
                if (end + 1 == n || path[end + 1] == '/') {
                    idx = end + 1;
                    continue;
                }
                // ..
                if (path[end + 1] == '.' &&
                    (end + 2 == n || path[end + 2] == '/')) {
                    if (!paths.empty())
                        paths.pop_back();
                    idx = end + 2;
                    continue;
                }
            }
            // 正常目录
            while (end < n && path[end] != '/')
                ++end;
            paths.push_back(path.substr(start, end - start));
            idx = end;
            continue;
        }
        for (auto &p : paths) {
            res += '/';
            res += p;
        }
        if (res.length() == 0)
            return "/";
        return res;
    }
};
int main() {
    string path = "/a//b////c/d//././/..";
    Solution *ss = new Solution();
    cout << ss->simplifyPath(path) << endl;
    return 0;
}