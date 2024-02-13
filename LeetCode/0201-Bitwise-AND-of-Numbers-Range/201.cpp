/*
 * @Date: 2024-02-13 10:17:48
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0201-Bitwise-AND-of-Numbers-Range/201.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
using namespace std;

// 找最长相同前缀
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            ++shift;
        }
        return left << shift;
    }
};
int main() {
    return 0;
}