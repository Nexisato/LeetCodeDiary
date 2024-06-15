#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 若成环则返回 true
 *
 */
class Solution {
public:
	bool isRobotBounded(string instructions) {
		pair<int, int> point = {0, 0};
		vector<string> directions({"N", "E", "S", "W"});
		int cur = 0;
		bool flag = false;

		function<void(string)> move = [&](string direction) -> void {
			if (direction == "N")
				++point.second;
			else if (direction == "S")
				--point.second;
			else if (direction == "W")
				--point.first;
			else if (direction == "E")
				++point.first;
		};

		for (const auto& instruction : instructions) {
			if (instruction == 'G') {
				move(directions[cur]);
			} else if (instruction == 'L') {
				cur = (cur + 3) % 4;
			} else {
				cur = (cur + 1) % 4;
			}
		}

		flag = (cur == 0) && ((point.first != 0) || (point.second != 0)); //不成环的条件
		flag = !flag;

		return flag;
	}
};
int main() {
	cout << (-1 + 4) % 4 << endl;
	return 0;
}