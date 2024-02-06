/*
 * @Date: 2024-02-06 09:55:53
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0212-Word-Search-II/212.cpp
 * @Description:
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Trie + DFS回溯搜索
// 容易超时，注意删除被匹配的单词
class Trie {
public:
    string cur;
    Trie *next[26];

    void addWord(string &word) {
        Trie *node = this;
        for (auto &c : word) {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->cur = word;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        const int m = board.size(), n = board[0].size();
        Trie *root = new Trie();
        for (auto &word : words) {
            root->addWord(word);
        }
        vector<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        function<void(int, int, Trie*)> dfs = [&](int x, int y, Trie *node) {
            if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y])
                return;
            char c = board[x][y];
            if (!node->next[c - 'a'])
                return;
            node = node->next[c - 'a'];
            if (!node->cur.empty()) {
                res.push_back(node->cur);
                node->cur.clear();
            }
            visited[x][y] = true;
            dfs(x + 1, y, node);
            dfs(x - 1, y, node);
            dfs(x, y + 1, node);
            dfs(x, y - 1, node);
            visited[x][y] = false;
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dfs(i, j, root);


        return res;
    }
};
int main() { return 0; }