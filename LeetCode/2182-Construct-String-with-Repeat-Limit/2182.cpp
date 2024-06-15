/*
 * @Date: 2024-01-13 11:07:56
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2182_Construct_String_with_Repeat_Limit/2182.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	string repeatLimitedString(string s, int repeatLimit) {
		int table[26];
		memset(table, 0, sizeof(table));
		for (const auto& c : s) {
			++table[c - 'a'];
		}
		string res;

		for (int i = 25, j = 24; ~i; --i) {
			j = min(j, i - 1);
			while (true) {
				int cnt = table[i] >= repeatLimit ? repeatLimit : table[i];
				table[i] -= cnt;
				res += string(cnt, 'a' + i);
				// 字符取完，直接 break
				if (table[i] == 0)
					break;
				while (j >= 0 && table[j] == 0)
					--j;
				if (j < 0)
					break;
				res += 'a' + j;
				--table[j];
			}
		}
		return res;
	}
};
int main() { return 0; }