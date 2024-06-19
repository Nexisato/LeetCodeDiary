/*
LeetCode
@Description:
某乐团的演出场地可视作 num * num 的二维矩阵 grid（左上角坐标为
[0,0])，每个位置站有一位成员。 乐团共有 9 种乐器，乐器编号为 1~9，每位成员持有 1
个乐器。

为保证声乐混合效果，成员站位规则为：自 grid 左上角开始顺时针螺旋形向内循环以
1，2，...，9 循环重复排列。 例如当 num = 5 时，站位如图所示

请返回位于场地坐标 [Xpos,Ypos] 的成员所持乐器编号
提示：
1 <= num <= 10^9
0 <= Xpos, Ypos < num
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool judgeEqual(int& x, int& y, int& xPos, int& yPos) {
		return (x == xPos) && (y == yPos);
	}

public:
	int orchestraLayout(int num, int xPos, int yPos) {
		int bnd = 0, x = 0, y = 0;
		long long count = 1, n = num;
		while (n != 0) {
			x = bnd, y = bnd;
			for (y = bnd; y < n; ++y) {
				if (judgeEqual(x, y, xPos, yPos))
					return count;
				count++;
				count %= 9;
				if (count == 0)
					count = 9;
			}
			y--;
			for (x = bnd + 1; x < n; ++x) {
				if (judgeEqual(x, y, xPos, yPos))
					return count;
				count++;
				count %= 9;
				if (count == 0)
					count = 9;
			}
			x--;
			for (y = n - 2; y >= bnd; --y) {
				if (judgeEqual(x, y, xPos, yPos))
					return count;
				count++;
				count %= 9;
				if (count == 0)
					count = 9;
			}
			y++;
			for (x = n - 2; x > bnd; --x) {
				if (judgeEqual(x, y, xPos, yPos))
					return count;
				count++;
				count %= 9;
				if (count == 0)
					count = 9;
			}
			x++;
			bnd++;
			n--;
		}
		return count;
	}
};

int main() {
	int num = 4, xPost = 2, yPos = 1;
	Solution ss;
	cout << ss.orchestraLayout(num, xPost, yPos) << endl;
	return 0;
}