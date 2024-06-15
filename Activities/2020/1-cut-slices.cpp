/*
Description:
假设要把长度为 n 厘米的木棒切分为 1 厘米长的小段，
但是 1 根木棒只能由 1 人切分，当木棒被切分为 3 段后，可以同时由 3 个人分别切分木棒
求最多有 m 个人时，最少要切分几次。譬如 n ＝ 8，m＝ 3 时如图所示，切分 4 次就可以了
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 正向思维：（可递归）
在每一次切分过程中，
-若 slices > m，说明人数为瓶颈，只有 m 段木棒会被切分
-若 slices <= m，说明木棒段数为瓶颈，切分后得到的木棒数翻倍
即每次切分后增加的段数为 min(slices,m)
2.逆向思维：
可以看作是m个人粘合n段木棒
- 若 slices/2 > m，说明人数为瓶颈，此轮粘合m段木棒
- 若 slices/2 <= m，说明段数为瓶颈，此轮木棒数被粘合一半
*/
class Solution {
public:
	int cutBar(int n, int m) {
		int slices = n;
		int res = 0;
		while (slices > 1) {
			++res;
			slices -= min(slices / 2, m);
		}
		return res;
	}
	int cutBar_recur(int n, int m, int cur) {
		if (cur >= n)
			return 0;
		else if (cur < m)
			return 1 + cutBar_recur(n, m, cur * 2);
		else
			return 1 + cutBar_recur(n, m, cur + m);
		return 0;
	}
};

int main() {
	Solution ss;
	int n = 100;
	int m = 5;
	cout << ss.cutBar(n, m) << endl;
	cout << ss.cutBar_recur(n, m, 1) << endl;
	return 0;
}