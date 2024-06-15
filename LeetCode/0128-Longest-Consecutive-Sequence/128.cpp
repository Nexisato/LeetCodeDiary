#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 最长的连续序列，不排序，要求时间复杂度为O(n)
// 用一个哈希表记录每个数是否出现过，然后遍历数组中的每个数，如果这个数没有出现过，那么我们就向当前数的左右两边搜索，
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int res = 0;
		unordered_map<int, bool> table;
		for (int& num : nums) {
			table[num] = false;
		}
		for (int& num : nums) {
			if (table[num])
				continue;
			int len = 1;
			table[num] = true;
			for (int i = num + 1; table.find(i) != table.end(); ++i) {
				table[i] = true;
				++len;
			}
			for (int i = num - 1; table.find(i) != table.end(); --i) {
				table[i] = true;
				++len;
			}
			res = max(res, len);
		}

		return res;
	}
};
int main() { return 0; }