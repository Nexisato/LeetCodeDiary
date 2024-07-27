/**
 * @Description:
* 小欧有一棵包含n个结点的树，每个结点有一个人，处在第i个结点的人想吃恰好i个苹果。
* 但他手里有 a^i 个苹果，可能不够吃，也可能太多了。
他们每次传递可以向树上相邻的结点传递1个苹果，小欧想知道，让所有人都恰好获得他想吃的苹果的数量总共需要有多少次传递？

LeetCode 979 原题：
 */
#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
#include <numeric>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> arr(n, INT32_MIN);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    unordered_map<int, vector<int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }
    int res = 0;
    function<int(int, int)> dfs = [&](int node, int parent) -> int {
        vector<int> subtrees;
        for (auto&& neighbor : edges[node]) {
            if (neighbor == parent) continue;
            int sub_delta = dfs(neighbor, node);
            subtrees.push_back(sub_delta);
            res += abs(sub_delta);
        }
        return accumulate(subtrees.begin(), subtrees.end(), 0) + arr[node] - (node + 1);
    };

    dfs(0, -1);




    cout << res << endl;
    return 0;
}