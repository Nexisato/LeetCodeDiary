/*
LeetCode
小扣当前位于魔塔游戏第一层，共有 N 个房间，编号为 0 ~ N-1。
每个房间的补血道具/怪物对于血量影响记于数组
nums，其中正数表示道具补血数值，即血量增加对应数值；负数表示怪物造成伤害值，
即血量减少对应数值；0 表示房间对血量无影响。

小扣初始血量为 1，且无上限。假定小扣原计划按房间编号升序访问所有房间补血/打怪，
为保证血量始终为正值，小扣需对房间访问顺序进行调整，每次仅能将一个怪物房间（负数的房间）调整至访问顺序末尾。
请返回小扣最少需要调整几次，才能顺利访问所有房间。若调整顺序也无法访问完全部房间，请返回
-1。

提示：
1 <= nums.length <= 10^5
-10^5 <= nums[i] <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class Solution {
public:
	int magicTower(vector<int>& nums) {
		int res = -1;
		int n = nums.size();
		long long checkSum = accumulate(nums.begin(), nums.end(), 0);
		if (checkSum < 0)
			return -1;
		long long tmpSum = 0;
		for (int i = 0; i < n; ++i) {
			tmpSum += nums[i];
		}
	}
};
int main() { return 0; }