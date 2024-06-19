#include <bits/stdc++.h>
using namespace std;
/*
逐位检查当然可以，那么当数组很大的时候呢
*/
// class Solution {
// public:
//     int numDupDigitsAtMostN(int n) {
//         int count = 0;
//         int table[10] = {0};
//         auto isRepeated = [&table](int num) -> bool {
//             while (num != 0) {
//                 int digit = num % 10;
//                 table[digit]++;
//                 if (table[digit] > 1)
//                     return true;
//                 num /= 10;
//             }
//             return false;
//         };
//         for (int num = 1; num <= n; num++) {
//             memset(table, 0, sizeof(table));
//             if (isRepeated(num))
//                 count++;
//         }
//         return count;
//     }
// };
class Solution {
public:
	int numDupDigitsAtMostN(int n) {
		auto s = to_string(n);
		int m = s.length(), memo[m][1 << 10];
		memset(memo, -1, sizeof(memo)); // -1 表示没有计算过
		function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit,
		                                            bool is_num) -> int {
			if (i == m)
				return is_num; // is_num 为 true 表示得到了一个合法数字
			if (!is_limit && is_num && memo[i][mask] != -1)
				return memo[i][mask];
			int res = 0;
			if (!is_num) // 可以跳过当前数位
				res = f(i + 1, mask, false, false);
			int up = is_limit ? s[i] - '0'
			                  : 9; // 如果前面填的数字都和 n 的一样，那么这一位至多填数字
			                       // s[i]（否则就超过 n 啦）
			for (int d = 1 - is_num; d <= up; ++d) // 枚举要填入的数字 d
				if ((mask >> d & 1) == 0)          // d 不在 mask 中
					res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
			if (!is_limit && is_num)
				memo[i][mask] = res;
			return res;
		};
		return n - f(0, 0, true, false);
	}
};
int main() {

	int n = 12345;
	string s = to_string(n);
	cout << s[0] << "\n";
	cout << (1 << 3) << endl;

	return 0;
}