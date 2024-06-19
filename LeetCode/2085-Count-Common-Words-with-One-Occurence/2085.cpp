/*
 * @Date: 2024-01-12 11:19:17
 * @Author: nexisato
 * @FilePath:
 * /LeetCodeDiary/LeetCode/2085_Count_Common_Words_with_One_Occurence/2085.cpp
 * @Description:
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 真得拿两个哈希表记
class Solution {
public:
	int countWords(vector<string>& words1, vector<string>& words2) {
		int res = 0;
		unordered_map<string, int> table1, table2;
		for (const string& word : words1) {
			table1[word]++;
		}
		for (const string& word : words2) {
			table2[word]++;
		}
		for (auto it = table1.begin(); it != table1.end(); ++it) {
			if (table2.find(it->first) != table2.end() && it->second == 1 &&
			    table2[it->first] == 1) {
				++res;
			}
		}

		return res;
	}
};

int main() { return 0; }