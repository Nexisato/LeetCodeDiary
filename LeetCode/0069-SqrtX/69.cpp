/*
 * @Date: 2024-02-11 21:01:58
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0069-SqrtX/69.cpp
 * @Description: 

 
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid <= x / mid && (mid + 1) > x / (mid + 1))
                return mid;
            else if (mid > x / mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
int main() {

    return 0;
}