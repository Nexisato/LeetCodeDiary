/*
LeetCode 1178: Number of Valid Words for Each Puzzle
@Description:
With respect to a given puzzle string, a word is valid if both the following conditions
are satisfied: · word contains the first letter of puzzle. · For each letter in word,
that letter is in puzzle.

For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and
"baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes
"s" which isn't in the puzzle). Return an array answer, where answer[i] is the number of
words in the given word list words that are valid with respect to the puzzle puzzles[i].

Constraints:
1 <= words.length <= 10^5
4 <= words[i].length <= 50
1 <= puzzles.length <= 10^4
puzzles[i].length == 7
words[i][j], puzzles[i][j] are English lowercase letters.
Each puzzles[i] doesn't contain repeated characters
*/
#include <bits/stdc++.h>
using namespace std;

/*

class Solution {
private:
    bool isValidWord(const string& word, char start, vector<bool>& table) {
        bool flag = false;
        for (auto& c : word) {
            if (!table[c - 'a'])
                return false;
            if (c == start)
                flag = true;
        }
        return flag;
    }
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res(puzzles.size(), 0);
        int i = 0;
        for (auto& puzzle : puzzles) {
            char start = puzzle[0];
            vector<bool> table(26, false);
            for (auto& c : puzzle)
                table[c - 'a'] = true;
            for (auto& word : words)
                res[i] = (isValidWord(word, start, table)) ? (res[i] + 1) : res[i];
            table.clear();
            ++i;
        }
        return res;
    }
};
*/
/*
思路：二进制状态压缩
1.
使用一个hash映射表示需要的[数据结构]，key表示一个bit长度为26的二进制数，value表示出现次数
2. 将word做转换方便查找，由于只有小写字母，所以可以用位操作来实现，a - z 对应 0 - 25
bit，转化为mask_word整数
3. 对于puzzle做同样的操作
4. 基于每个puzzle找对应word的转换
    · 首先保证puzzle[0]在对应的bit在mask_word中也同样为1
    · 枚举mask_puzzle各种为1的情况是否能找到对应的mask_word，找到则加上当映射的数量即可
5. make_puzzle枚举方法： a = (a - 1) & mask，不断去除1位1，直到 a == mask
*/
class Solution {
private:
	inline int BitCount(int x) {
		int res = 0;
		while (x > 0) {
			res += (x & 1);
			x >>= 1;
		}
		return res;
	}

public:
	vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
		unordered_map<int, int> table;
		for (const string& word : words) {
			int mask = 0;
			for (char& c : word)
				mask |= (1 << (c - 'a'));
			// puzzle.length() = 7，且各字符不同，因此字符不同数目大于7时即可跳过
			if (BitCount(mask) <= 7)
				table[mask]++;
		}
		vector<int> res;
		for (auto& puzzle : puzzles) {
			int mask = 0;
			//忽略puzzle[0]
			for (int i = 1; i < 7; ++i)
				mask |= (1 << (puzzle[i] - 'a'));
			int start = 1 << (puzzle[0] - 'a');
			int currMask = mask, total = 0, curr = 0;
			do {
				curr = currMask | start;
				if (table.count(curr))
					total += table[curr];
				currMask = (currMask - 1) & mask;
			} while (currMask != mask);
			res.emplace_back(total);
		}
		return res;
	}
};
/*
思路：字典树
*/

int main() { return 0; }