/*
 * @Date: 2024-01-30 11:54:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0134-Gas-Station/134.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 固定一点，向后移动看能不能计数 n 次
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int idx = 0;
        while (idx < n) {
            int sum_gas = 0, sum_cost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (idx + cnt) % n;
                sum_gas += gas[j];
                sum_cost += cost[j];
                if (sum_cost > sum_gas)
                    break;
                ++cnt;
            }
            if (cnt == n)
                return idx;
            else 
                idx = idx + cnt + 1;
        }
        return -1;
    }
};
int main() {

    return 0;
}