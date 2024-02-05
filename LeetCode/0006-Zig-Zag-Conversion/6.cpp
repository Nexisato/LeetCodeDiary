/*
 * @Date: 2024-02-05 07:49:50
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0006-Zig-Zag-Conversion/6.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * 
 * P P I I N
 * A A S R G
 * Y L H I
*/

// 每一行下一个字符多 2 * numRows - 2
// 中间行还要多一个字符，间隔为 2 * numRows - 2 - i
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int mod = 2 * numRows - 2;
        if (mod == 0) {
            return s;
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j + i < s.size(); j += mod) {
                res += s[j + i];
                if (i != 0 && i != numRows - 1 && j + mod - i < s.size()) {
                    res += s[j + mod - i];
                }
            }
        }
        return res;
    }
};
int main() {

    return 0;
}