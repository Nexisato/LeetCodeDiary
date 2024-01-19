/*
 * @Date: 2024-01-19 10:53:43
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0207-Course-Schedule/207.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    // 拓扑排序
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDeg(numCourses, 0);
        // DAG construction
        for (const auto& pre : prerequisites) {
            inDeg[pre[0]]++;
            edges[pre[1]].push_back(pre[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (inDeg[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ++cnt;
            for (const auto& next : edges[cur]) {
                --inDeg[next];
                if (inDeg[next] == 0)
                    q.push(next);
            }
        }
        return cnt == numCourses;
    }
};
int main() {

    return 0;
}