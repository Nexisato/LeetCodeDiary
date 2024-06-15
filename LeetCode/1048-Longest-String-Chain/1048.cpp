#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 思路：连着好多天的 DP
 * 这里不用开 dp 数组，一次去掉 current word 的每个字母，与哈希表中的 prev_word 进行对比
 *
 */
class Solution {
public:
	int longestStrChain(vector<string>& words) {
		const int n = words.size();
		sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() < b.length(); });
		int res = -1;
		unordered_map<string, int> table;
		for (auto word : words) {
			table[word] = 1;
			for (int i = 0; i < word.length(); ++i) {
				string s = word.substr(0, i) + word.substr(i + 1); //依次去掉每个字母
				if (table.count(s)) {
					table[word] = max(table[word], table[s] + 1);
				}
			}
			res = max(res, table[word]);
		}
		return res;
	}
};
int main() { return 0; }