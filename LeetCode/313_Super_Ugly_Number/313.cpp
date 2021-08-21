/*
LeetCode 313: Super Ugly Number
@Description:
A super ugly number is a positive integer whose prime factors are in the array primes.

Given an integer n and an array of integers primes, return the nth super ugly number.

The nth super ugly number is guaranteed to fit in a 32-bit signed integer.

Constraints:
1 <= n <= 10^6
1 <= primes.length <= 100
2 <= primes[i] <= 1000
primes[i] is guaranteed to be a prime number.
All the values of primes are unique and sorted in ascending order.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /*
    思路：最小堆
        1 是最小的丑数
    */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        unordered_set<long long> seen;
        minHeap.push(1);
        seen.insert(1);
        int res = 1;
        for (int i = 0; i < n; ++i) {
            long long cur = minHeap.top();
            res = (int)cur;
            minHeap.pop();
            for (int prime : primes) {
                long long num = prime * cur;
                if (seen.find(num) == seen.end()) {
                    seen.insert(num);
                    minHeap.push(num);
                }
            } 
        }
        return res;
    }
};
int main() {

    return 0;
}