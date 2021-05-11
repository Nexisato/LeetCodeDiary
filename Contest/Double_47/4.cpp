/*
LeetCode 5683: Count Pairs of Nodes
@Description:
You are given an undirected graph represented by an integer n, 
which is the number of nodes, and edges, where edges[i] = [ui, vi] which indicates 
that there is an undirected edge between ui and vi. You are also given an integer array queries.

The answer to the jth query is the number of pairs of nodes (a, b) that satisfy the following conditions:
- a < b
- cnt is strictly greater than queries[j], where cnt is the number of edges incident to a or b.

Return an array answers such that answers.length == queries.length and answers[j] 
is the answer of the jth query.

Note that there can be repeated edges.

Constraints:
2 <= n <= 2 * 10^4
1 <= edges.length <= 10^5
1 <= ui, vi <= n
ui != vi
1 <= queries.length <= 20
0 <= queries[j] < edges.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：容斥原理
1. 与点a、b相连的边数等于[与a相连的边数加上与b相连的边数，再减去与a,b同时相连的边数]
2. 考虑的二维数组的时空开销过大，因此我们用hashtable节省空间使用
    - pmax = max(p1, p2); pmin = min(p1, p2)
    - 将这条边映射到 pmax*(n + 1) + pmin
3. 需要求出点对(a, b)的数量，使得deg[a]+deg[b]-overlap[a][b]>query
    - 等价于求出deg[a]+deg[b]>query 但 deg[a] + deg[b] - overlap[a][b] <= query 的数量
*/
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        int n_edges = edges.size();
        auto encode = [n](int a, int b) -> int{return max(a, b) * (n + 1) + min(a, b);};
        unordered_map<int, int> overlap;
        vector<vector<int>> graph;//不记录重边
        for (int i = 0; i < n_edges; ++i) {
            int a = edges[i][0], b = edges[i][1];
            deg[a]++;
            deg[b]++;
            int idx = encode(a, b);
            if (overlap.find(idx) == overlap.end())
                graph.push_back({a, b});
            overlap[idx]++;
        }
        int n_graph = graph.size();
        vector<int> sortedDeg(deg.begin() + 1, deg.end());
        sort(sortedDeg.begin(), sortedDeg.end());

        int n_queries = queries.size();
        vector<int> res(n_queries, 0);
        for (int i = 0; i < n_queries; ++i) {
            int l = 0, r = n - 1;
            int cnt = 0;
            //有序数组中，满足两数之和大于特定值的所有数字对的个数
            while (l < n) {
                while (r > l && sortedDeg[l] + sortedDeg[r] > queries[i])
                    r--;
                cnt += (n - 1 - max(l ,r));
                l++;
            }
            for (int j = 0; j < n_graph; ++j) {
                int p = graph[j][0], q = graph[j][1];
                int idx = encode(p, q);
                int sum = deg[p] + deg[q];
                if (sum > queries[i] && sum - overlap[idx] <= queries[i])
                    cnt--;
            }
            res[i] = cnt;
        }
        return res;
    }
};
int main() {

    return 0;
}