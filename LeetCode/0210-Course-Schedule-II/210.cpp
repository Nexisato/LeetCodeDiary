/*
 * @Date: 2024-01-19 10:59:56
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0210-Course-Schedule-II/210.cpp
 * @Description:
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> edges(numCourses);
		vector<int> inDeg(numCourses, 0);
		// DAG construction
		for (const auto& pre : prerequisites) {
			inDeg[pre[0]]++;
			edges[pre[1]].push_back(pre[0]);
		}
		queue<int> q;
		for (int i = 0; i < numCourses; ++i)
			if (inDeg[i] == 0)
				q.push(i);
		int cnt = 0;
		vector<int> res; // 用于存储拓扑排序结果
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			++cnt;
			res.push_back(cur);
			for (const auto& next : edges[cur]) {
				--inDeg[next];
				if (inDeg[next] == 0)
					q.push(next);
			}
		}
		// 因为是全部的课程，所以如果不是全部都能上，就返回空
		return cnt == numCourses ? res : vector<int>();
	}
};
int main() { return 0; }