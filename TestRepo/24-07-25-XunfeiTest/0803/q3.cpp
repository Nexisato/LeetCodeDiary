#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 只记录第三题，典型的树桩DP

// 定义树节点结构
struct TreeNode {
    int weight;
    vector<int> children;
};

// 深度优先搜索函数
void dfs(int node, int parent, const vector<TreeNode>& tree, vector<vector<int>>& dp, int& maxLength, bool increasing) {
    if (increasing) {
        dp[node][0] = 1; // 初始化当前节点为1，表示满足 weight[i] <= weight[fa[i]]
    } else {
        dp[node][1] = 1; // 初始化当前节点为1，表示满足 weight[i] >= weight[fa[i]]
    }

    for (int child : tree[node].children) {
        if (child == parent) continue; // 跳过父节点

        dfs(child, node, tree, dp, maxLength, increasing);

        // 如果满足 weight[i] <= weight[fa[i]]
        if (tree[child].weight <= tree[node].weight) {
            maxLength = max(maxLength, dp[node][0] + dp[child][0]);
            dp[node][0] = max(dp[node][0], dp[child][0] + 1);
        }

        // 如果满足 weight[i] >= weight[fa[i]]
        if (tree[child].weight >= tree[node].weight) {
            maxLength = max(maxLength, dp[node][1] + dp[child][1]);
            dp[node][1] = max(dp[node][1], dp[child][1] + 1);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode> tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree[i].weight;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u - 1].children.push_back(v - 1);
        tree[v - 1].children.push_back(u - 1);
    }

    // dp[i][0] 表示以节点 i 为根节点，的满足 weight[i] <= weight[fa[i]] 的最长链路长度
    // dp[i][1] 表示以节点 i 为终点的满足 weight[i] >= weight[fa[i]] 的最长链路长度
    vector<vector<int>> dp(n, vector<int>(2, 0)); 
                                                  
    int maxLength = 0;

    dfs(0, -1, tree, dp, maxLength, true);  // 从根节点开始遍历，初始状态为 increasing
    dfs(0, -1, tree, dp, maxLength, false); // 从根节点开始遍历，初始状态为 decreasing

    cout << maxLength << endl;

    return 0;
}