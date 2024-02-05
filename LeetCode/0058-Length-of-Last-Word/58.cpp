/*
 * @Date: 2024-02-04 08:36:13
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0058-Length-of-Last-Word/58.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (res == 0)
                    continue;
                break;
            }
            ++res;
        }

        return res;
    }
};
int main() {

    return 0;
}