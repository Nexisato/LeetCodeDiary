/*
 * @Date: 2024-02-01 22:36:04
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LCP/0024-DigitalGame.cpp
 * @Description: 
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//OS: 我就喜欢 Hard 题
// 本题是找动态的中位数，这里将中位数移动到 rHeap 的堆顶方便计算
class Solution {
public:
    vector<int> numsGame(vector<int>& nums) {
        const int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<int> res(n);
        priority_queue<int, vector<int>, less<int>> lHeap;
        priority_queue<int, vector<int>, greater<int>> rHeap;
        long long lSum = 0, rSum = 0;
        // 本题是找动态的中位数
        for (int i = 0; i < n; ++i) {
            int bi = nums[i] - i;
            
            // 动态维护中位数对顶堆
            // 前缀长度是奇数，左右堆大小相等
            if (i % 2 == 0) {
                if (!lHeap.empty() && bi < lHeap.top()) {
                    lSum += (bi - lHeap.top());
                    lHeap.push(bi);
                    bi = lHeap.top();
                    lHeap.pop();
                } 
                rSum += bi;
                rHeap.push(bi);

                res[i] = (rSum - lSum - rHeap.top()) % mod;

            } else {
                if (!rHeap.empty() && bi > rHeap.top()) {
                    rSum += (bi - rHeap.top());
                    rHeap.push(bi);
                    bi = rHeap.top();
                    rHeap.pop();
                }
                lSum += bi;
                lHeap.push(bi);
                res[i] = (rSum - lSum) % mod;
            }
        
        }
        return res;
    }
};
int main() {

    return 0;
}