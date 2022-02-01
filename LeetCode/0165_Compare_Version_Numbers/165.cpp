/*
LeetCode 165: Compare Version Numbers
@Description:
Given two version numbers, version1 and version2, compare them.

Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and 
may contain leading zeros. Every revision contains at least one character. 
Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, 
the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

To compare version numbers, compare their revisions in left-to-right order. 
Revisions are compared using their integer value ignoring any leading zeros. 
This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, 
then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, 
but their revision 1s are 0 and 1 respectively, and 0 < 1.

Return the following:
- If version1 < version2, return -1.
- If version1 > version2, return 1.
- Otherwise, return 0.
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
/*
思路：双指针，按分割点比较数大小
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length(), l2 = version2.length();
        int i = 0, j = 0;
        while (i < l1 || j < l2) {
            int x = 0, y = 0;
            for (; i < l1 && version1[i] != '.'; ++i)
                x = x * 10 + version1[i] - '0';
            ++i; //非常重要，跳过分割点
            for (; j < l2 && version2[j] != '.'; ++j)
                y = y * 10 + version2[j] - '0';
            ++j;
            if (x != y)
                return (x > y) ? 1 : (-1);
        }
        return 0;
    }
};
int main() {

    return 0;
}