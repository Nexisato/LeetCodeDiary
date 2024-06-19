#include <bits/stdc++.h>
using namespace std;

/*
朴素解法：直接遍历 + 排序
*/
class Solution {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
	                                      vector<vector<int>>& items2) {
		vector<vector<int>> ret = items1;
		for (int i = 0; i < items2.size(); ++i) {
			vector<int> item_i = items2[i];
			bool isAdded = false;
			for (int j = 0; j < items1.size(); ++j) {
				if (item_i[0] == items1[j][0]) {
					ret[j][1] += item_i[1];
					isAdded = true;
					break;
				}
			}
			if (!isAdded)
				ret.emplace_back(item_i);
		}
		sort(ret.begin(), ret.end(),
		     [](vector<int> item1, vector<int> item2) { return item1[0] < item2[0]; });
		return ret;
	}
};
/*
题解解法：哈希表
*/
class Solution_2 {
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
	                                      vector<vector<int>>& items2) {
		map<int, int> table;
		for (auto& item : items1)
			table[item[0]] += item[1];
		for (auto& item : items2)
			table[item[0]] += item[1];
		vector<vector<int>> ret;
		for (auto& [k, v] : table) {
			ret.push_back({k, v});
		}
		return ret;
	}
};
int main() { return 0; }