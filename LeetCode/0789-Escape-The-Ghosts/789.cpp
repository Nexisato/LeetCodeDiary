/*
LeetCode 789: Escape The Ghosts
@Description:
You are playing a simplified PAC-MAN game on an infinite 2-D grid. You start at the
point [0, 0], and you are given a destination point target = [xtarget, ytarget], which
you are trying to get to. There are several ghosts on the map with their starting
positions given as an array ghosts, where ghosts[i] = [xi, yi] represents the starting
position of the ith ghost. All inputs are integral coordinates.

Each turn, you and all the ghosts may independently choose to either move 1 unit in any
of the four cardinal directions: north, east, south, or west or stay still. All actions
happen simultaneously.

You escape if and only if you can reach the target before any ghost reaches you.
If you reach any square (including the target) at the same time as a ghost, it does not
count as an escape.

Return true if it is possible to escape, otherwise return false.

Constraints:
1 <= ghosts.length <= 100
ghosts[i].length == 2
-10^4 <= xi, yi <= 10^4
There can be multiple ghosts in the same location.
target.length == 2
-10^4 <= xtarget, ytarget <= 10^4
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：曼哈顿距离法
1. 所有人都会按照各自最短的距离到达 target
2. 每个人到达 target 都是按照曼哈顿距离的走法到达
3. 无需考虑各自按照怎样的路线走
    - 当有阻碍者可以先于或同时与玩家到达目的地，则逃跑失败
    -
当玩家先于所有阻碍者到达目的地时，则一定可以逃跑成功，可以利用反证法证明一定不会在路中间遇到
*/
class Solution {
public:
	bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
		int n = ghosts.size();
		int targetX = target[0], targetY = target[1];
		auto dist = [&](int x, int y) { return abs(targetX - x) + abs(targetY - y); };
		int distPlayer = dist(0, 0);
		for (int i = 0; i < n; ++i) {
			int ghostX = ghosts[i][0], ghostY = ghosts[i][1];
			if (dist(ghostX, ghostY) <= distPlayer)
				return false;
		}
		return true;
	}
};
int main() { return 0; }