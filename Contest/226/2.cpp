/*
LeetCode 5665: Restore the Array From Adjacent Pairs
Description:
There is an integer array nums that consists of n UNIQUE elements, 
but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 
where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will 
exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. 
The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of them.

Constraints:
nums.length == n
adjacentPairs.length == n - 1
adjacentPairs[i].length == 2
2 <= n <= 10^5
-10^5 <= nums[i], ui, vi <= 10^5
There exists some nums that has adjacentPairs as its pairs.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
由于所有数字都不同，因此首尾两个数字只会出现一次
因此，我们从任意一个只出现一次的数字开始，用类似拓扑排序的方法还原整个数组（或其逆序）
*/
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in_deg;
        for (auto& v : adjacentPairs) {
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
            in_deg[v[0]]++;
            in_deg[v[1]]++;
        }
        int start;
        for (auto it = in_deg.begin(); it != in_deg.end(); it++) {
            if (it->second == 1) {
                start = it->first;
                break;
            }
        }
        
        //还原数组
        queue<int> q;
        q.emplace(start);
        vector<int> res;
        unordered_set<int> vis;
        vis.emplace(start);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            res.emplace_back(u);
            for (int v : adj[u]) 
                if (!vis.count(v)) {
                    vis.emplace(v);
                    q.emplace(v);
                }
        }
        return res;
    }
};
int main() {

    Solution ss;
    return 0;
}