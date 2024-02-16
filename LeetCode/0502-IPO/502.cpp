/*
 * @Date: 2024-02-15 09:03:56
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0502-IPO/502.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++i)
            projects.push_back({capital[i], profits[i]});
        sort(projects.begin(), projects.end());
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0, j = 0; i < k; ++i) {
            while (j < n && projects[j].first <= w) {
                pq.push(projects[j].second);
                j++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            }
        }


        return w;
    }
};
int main() {
    return 0;
}