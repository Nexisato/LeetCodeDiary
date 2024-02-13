/*
 * @Date: 2024-02-13 09:26:02
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0987-Vertical-Order-Traversal-of-Binary-Tree/987.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 最重要的是记录一下哈希表，根据列号来记录每个节点的行号和值
class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> res;
		unordered_map<int, vector<pair<int, int>>> table;
		int minCol = INT_MAX, maxCol = INT_MIN;
		function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int row, int col) {
			if (!node)
				return;
			table[col].push_back({row, node->val});
			minCol = min(minCol, col);
			maxCol = max(maxCol, col);
			dfs(node->left, row + 1, col - 1);
			dfs(node->right, row + 1, col + 1);
		};
		dfs(root, 0, 0);
		for (int i = minCol; i <= maxCol; ++i) {
			sort(table[i].begin(), table[i].end(), 
                    [](const pair<int, int>& a, const pair<int, int>& b) {
				return a.first == b.first ? a.second < b.second : a.first < b.first;
			});

			vector<int> col;
			for (auto& [_, val] : table[i]) {
				col.push_back(val);
			}
			res.push_back(col);
		}

		return res;
	}
};

int main() { return 0; }
