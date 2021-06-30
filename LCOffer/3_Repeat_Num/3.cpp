/*
LCOffer: 数组中重复的数字
@Description:
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，
但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

限制：
2 <= n <= 100000
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> record;
        for (auto& num : nums) {
            if (record.count(num))
                return num;
            record.insert(num);
        }
        return -1;
    }
};
int main() {

    return 0;
}