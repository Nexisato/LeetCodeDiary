#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int cur, vector<bool>& visited, vector<vector<int>>& edges, vector<vector<bool>>& isPre) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = true;
        for (auto& neighbor : edges[cur]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, edges, isPre);
            }
            isPre[cur][neighbor] = true;
            for (int i = 0; i < isPre.size(); ++i) {
                isPre[cur][i] = isPre[cur][i] | isPre[neighbor][i];
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> edges(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            int src = prerequisites[i][0], dst = prerequisites[i][1];
            edges[src].push_back(dst);
        }
        vector<bool> visited(numCourses, false);
        vector<vector<bool>> isPre(numCourses, vector<bool>(numCourses, false));
        for (int i = 0; i < numCourses; ++i)
            dfs(i, visited, edges, isPre);
        vector<bool> ans;
        for (int i = 0; i < queries.size(); ++i) {
            int src = queries[i][0], dst = queries[i][1];
            ans.push_back(isPre[src][dst]);
        }
        return ans;
    }
};



int main() {


    return 0;
}