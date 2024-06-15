#include <bits/stdc++.h>
using namespace std;
/*
class Trie {
private:
    bool isEnd = false;
    Trie* next[26];

public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    void insert(string word) {
        Trie* node = this;
        for (auto c : word) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
        }
        node->isEnd = true;
    }
    bool searchPrefix(string word) {
        Trie *node = this;
        for (auto c : word) {
            int idx = c - 'a';
            if (!node->next[idx])
                return false;
            node = node->next[idx];
        }
        return true;
    }

};
*/
/*
 * 思路：dp，用两个数组 post[i][j], prefix[i][j]
      记录分别以字符s[i], t[j] 结尾的最长相同后缀的长度，和以其开头的最长相同前缀的长度
*/
class Solution {
public:
	int countSubstrings(string s, string t) {
		int res = 0;
		int m = s.length(), n = t.length();
		int post[m + 1][n + 1], prefix[m + 1][n + 1];
		memset(post, 0, sizeof(post));
		memset(prefix, 0, sizeof(prefix));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (s[i] == t[j])
					post[i + 1][j + 1] = post[i][j] + 1;
		for (int i = m - 1; i >= 0; --i)
			for (int j = n - 1; j >= 0; --j)
				if (s[i] == t[j])
					prefix[i][j] = prefix[i + 1][j + 1] + 1;
				else
					res += (post[i][j] + 1) * (prefix[i + 1][j + 1] + 1);

		return res;
	}
};

int main() { return 0; }