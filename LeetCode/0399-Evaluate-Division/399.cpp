/*
 * @Date: 2024-01-07 13:51:50
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0399_Evaluate_Division/399.cpp
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
	                            vector<vector<string>>& queries) {
		// CORE: 用二重哈希表，首先构建一张图
		unordered_map<string, unordered_map<string, double>> record;
		for (int i = 0; i < equations.size(); ++i) {
			string Ai = equations[i][0], Bi = equations[i][1];
			double val = values[i];
			record[Ai][Bi] = val;
			record[Bi][Ai] = 1.0 / val;
			record[Ai][Ai] = 1.0;
			record[Bi][Bi] = 1.0;
		}
		auto calc = [&](string& Ci, string& Di) -> double {
			if (record.find(Ci) == record.end() || record.find(Di) == record.end())
				return -1.0;
			if (Ci == Di)
				return 1.0;
			unordered_set<string> visited;
			visited.insert(Ci);
			queue<pair<string, double>> q;
			// 队列用于记录当前节点的所有邻接节点
			q.push({Ci, 1.0});
			while (!q.empty()) {
				auto [cur, val] = q.front();
				// string cur = q.front();
				q.pop();
				for (auto& it : record[cur]) {
					if (visited.find(it.first) != visited.end())
						continue;
					// 目标节点到达了，直接返回数值即可
					if (it.first == Di)
						return val * it.second;
					visited.insert(it.first);
					q.push({it.first, val * it.second});
				}
			}
			return -1.0;
		};

		vector<double> res(queries.size(), -1.0);
		for (int i = 0; i < queries.size(); ++i) {
			string Ci = queries[i][0], Di = queries[i][1];
			res[i] = calc(Ci, Di);
		}

		return res;
	}
};
int main() { return 0; }