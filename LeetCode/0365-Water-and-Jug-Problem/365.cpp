/*
 * @Date: 2024-01-28 08:48:05
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0365-Water-and-Jug-Problem/365.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

// 这里只给两个水壶，别乱倒
// 容量不够，倒不了；加起来或其中一个壶的容量等于目标容量，直接返回 true
// 其他一般情况，只要目标容量是两个壶容量的最大公约数的倍数，就可以倒出来
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity,
                         int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        function<int(int, int)> gcd = [](int x, int y) -> int {
            int m = max(x, y), n = min(x, y);
            if (n == 0)
                return m;
            int z = 0;
            while (m % n) {
                z = n;
                n = m % n;
                m = z;
            }
            return n;
        };
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity ||
            (jug1Capacity + jug2Capacity) == targetCapacity)
            return true;

        int g = gcd(jug1Capacity, jug2Capacity);
        return targetCapacity % g == 0;
    }
};
int main() { return 0; }