#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;



class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prev(n + 1, 0);
        // prev[i] 表示 i 的先修课程集合，以二进制状态位进行表示
        for (auto&& relation : relations) {
            int xi = relation[0], yi = relation[1];
            prev[yi] |= (1 << xi);  
        }
        int cur = 0;
        // cur == 2 ^ (n + 1) - 2 时，表示所有课程已经修完
        queue<pair<int, int>> q;
        q.push({0 ,0}); // cur (当前已经上的课的集合，上课轮数)
        unordered_set<int> visited({0});
        while (!q.empty()) {
            auto [cur, count] = q.front();
            q.pop();
            if (cur == ((1 << (n + 1)) - 2)) {
                return count;
            }
            int next = 0;
            // 前置的课程全部学完
            for (int i = 1; i <= n; ++i) {
                if ((cur & prev[i]) == prev[i]) {
                    next |= (1 << i);
                }
            }
            next ^= cur;
            if (__builtin_popcount(next) <= k) {
                if (!visited.count(next | cur)) {
                    visited.insert(next | cur);
                    q.push({next | cur, count + 1});
                }
            } else {
                int x = next;
                while (next) {
                    if (__builtin_popcount(next) == k && !visited.count(next | cur)) {
                        visited.insert(next | cur);
                        q.push({next | cur, count + 1});
                    }
                    next = (next - 1) & x;
                }
            }
        }
        return 0;
    }
};


int main() {


    return 0;
}