/*
 * @Date: 2024-01-07 13:18:29
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0433_Minimum_Genetic_Mutation/433.cpp
 * @Description: 
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// BFS, 不要 DFS
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 目标基因不在基因库中，直接返回-1
        if (bank.empty()) return -1;
        if (find(bank.begin(), bank.end(), endGene) == bank.end()) return -1;
        if (startGene == endGene) return 0;
        queue<string> q;
        vector<bool> visited(bank.size(), false);
        q.push(startGene);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            ++res;
            // BFS 遍历框架
            for (int i = 0; i < size; ++i) {
                string cur = q.front();
                q.pop();
                // 记录已经搜索过的基因
                for (int k = 0; k < bank.size(); ++k) {
                    if (visited[k]) continue;
                    int diff = 0;
                    for (int j = 0; j < startGene.size(); ++j) {
                        if (cur[j] != bank[k][j]) ++diff;
                        else continue;
                    }
                    if (diff == 1) {
                        if (bank[k] == endGene) return res;
                        q.push(bank[k]);
                        visited[k] = true;
                    }
                }
            }
        }
        return -1;
    }
};
int main() {


    return 0;
}