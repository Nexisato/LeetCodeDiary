/*
LeetCode
@Description:
某解密游戏中，有一个 N*M 的迷宫，迷宫地形会随时间变化而改变，迷宫出口一直位于 (n-1,m-1)
位置。 迷宫变化规律记录于 maze 中，maze[i] 表示 i 时刻迷宫的地形状态，"."
表示可通行空地，"#" 表示陷阱。

地形图初始状态记作 maze[0]，此时小力位于起点
(0,0)。此后每一时刻可选择往上、下、左、右其一方向走一步， 或者停留在原地。

小力背包有以下两个魔法卷轴（卷轴使用一次后消失）：
临时消除术：将指定位置在下一个时刻变为空地；
永久消除术：将指定位置永久变为空地。
请判断在迷宫变化结束前（含最后时刻），小力能否在不经过任意陷阱的情况下到达迷宫出口呢？

注意： 输入数据保证起点和终点在所有时刻均为空地。

提示：
1 <= maze.length <= 100
1 <= maze[i].length, maze[i][j].length <= 50
maze[i][j] 仅包含 "."、"#"
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool escapeMaze(vector<vector<string>>& maze) {
		int N = maze[0].size(), M = maze[0][0].length(), n = maze.size();

		for (int i = 0; i < n - 1; ++i) {
		}
	}
};
int main() { return 0; }