/*
LeetCode: 457 Circular Array Loop
You are playing a game involving a circular array of non-zero integers nums.
Each nums[i] denotes the number of indices forward/backward you must move if you are
located at index i:

- If nums[i] is positive, move nums[i] steps forward, and
- If nums[i] is negative, move nums[i] steps backward.

Since the array is circular, you may assume that moving forward from the last element
puts you on the first element, and moving backwards from the first element puts you on
the last element.

A cycle in the array consists of a sequence of indices seq of length k where:

- Following the movement rules above results in the repeating index sequence
   seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
- Every nums[seq[j]] is either all positive or all negative.
- k > 1

Return true if there is a cycle in nums, or false otherwise.

Constraints:
1 <= nums.length <= 5000
-1000 <= nums[i] <= 1000
nums[i] != 0
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	思路：拓扑排序，即找图中有无环

	*/
	bool toposort(vector<vector<int>>& graph, vector<int>& inDeg) {
		int n = inDeg.size();
		queue<int> q;
		for (int i = 0; i < n; ++i)
			if (inDeg[i] == 0)
				q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int neighbor : graph[cur]) {
				--inDeg[neighbor];
				if (inDeg[neighbor] == 0)
					q.push(neighbor);
			}
		}
		//若图中存在环，则经过topo排序后仍存在非0的入度
		for (int num : inDeg)
			if (num != 0)
				return true;
		return false;
	}
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> graph(n, vector<int>());
		vector<int> inDeg(n, 0);
		//正向序列
		bool noEmpty = false;
		for (int i = 0; i < n; ++i) {
			int next = ((i + nums[i]) % n + n) % n;
			if (nums[i] < 0 || next == i)
				continue;
			graph[i].emplace_back(next);
			noEmpty = true;
			++inDeg[next];
		}
		if (noEmpty)
			if (toposort(graph, inDeg))
				return true;
		graph.clear();
		inDeg.clear();
		graph.resize(n);
		inDeg.resize(n);
		noEmpty = false;
		//反向序列
		for (int i = 0; i < n; ++i) {
			int next = ((i + nums[i]) % n + n) % n;
			if (nums[i] > 0 || next == i)
				continue;
			noEmpty = true;
			graph[i].emplace_back(next);
			++inDeg[next];
		}
		if (noEmpty)
			;
		return toposort(graph, inDeg);
		return false;
	}
};
int main() {
	vector<int> nums({-1, 2});
	Solution* ss = new Solution();
	bool res = ss->circularArrayLoop(nums);
	return 0;
}