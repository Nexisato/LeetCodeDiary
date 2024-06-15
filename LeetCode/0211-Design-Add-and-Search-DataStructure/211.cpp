/*
 * @Date: 2024-02-05 10:28:20
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0211-Design-Add-and-Search-DataStructure/211.cpp
 * @Description:
 */
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
public:
	bool isEnd;
	unordered_map<char, Trie*> table;
	Trie() : isEnd(false) {}
};

class WordDictionary {
private:
	Trie* root;

public:
	WordDictionary() { root = new Trie(); }

	void addWord(string word) {
		Trie* node = this->root;
		for (auto& c : word) {
			if (!node->table.count(c)) {
				node->table[c] = new Trie();
			}
			node = node->table[c];
		}
		node->isEnd = true;
	}

	bool search(string word) {
		Trie* node = this->root;
		bool res = false;
		function<bool(int, Trie*)> dfs = [&](int idx, Trie* node) -> bool {
			if (idx == word.size()) {
				return node->isEnd;
			}
			if (word[idx] == '.') {
				for (auto& [c, next] : node->table) {
					if (dfs(idx + 1, next)) {
						return true;
					}
				}
				return false;
			} else {
				if (!node->table.count(word[idx])) {
					return false;
				}
				return dfs(idx + 1, node->table[word[idx]]);
			}
		};
		res = dfs(0, node);
		return res;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() { return 0; }