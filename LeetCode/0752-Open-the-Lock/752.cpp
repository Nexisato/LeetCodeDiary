/*
LeetCode 752: Open the Lock
@Description:
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots:
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around:
for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes,
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns
required to open the lock, or -1 if it is impossible.

Constraints:
1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
private:
	inline int to_Code(string& s) {
		int count = 0;
		for (int i = 3; i >= 0; --i)
			count = count * 10 + (s[i] - '0');
		return count;
	}

public:
	int openLock(vector<string>& deadends, string target) {
		int n = deadends.size();
		string initStr = "0000";
		vector<bool> visited(10000, false);
		int step = -1;
		for (auto s : deadends)
			visited[to_Code(s)] = true;
		if (visited[0] == true)
			return -1;
		queue<string> q;
		q.push(initStr);
		visited[0] = true;
		while (!q.empty()) {
			int size = q.size();
			++step;
			for (int i = 0; i < size; ++i) {
				string node = q.front();
				if (node == target)
					return step;
				q.pop();
				visited[to_Code(node)] = true;
				for (int i = 0; i <= 3; ++i) {
					string up = node, down = node;
					up[i] = (up[i] == '9') ? '0' : (up[i] + 1);
					down[i] = (down[i] == '0') ? '9' : (down[i] - 1);
					if (!visited[to_Code(up)]) {
						q.push(up);
						visited[to_Code(up)] = true;
					}
					if (!visited[to_Code(down)]) {
						q.push(down);
						visited[to_Code(down)] = true;
					}
				}
			}
		}
		return -1;
	}
};
int main() { return 0; }