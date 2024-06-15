/*
LeetCode 421: Maximum XOR of Two Numbers in an Array
@Description:
Given an integer array nums, return the maximum result of nums[i] XOR nums[j],
where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

Constraints:
1 <= nums.length <= 2 * 104
0 <= nums[i] <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：字典树的应用
1. x = nums[i] ^ nums[j]，二重循环枚举，很容易超时 nums[j] = x ^ nums[i];
- 设计一种 [从高位到低位依次确定x的二进制表示的每一位] 的方法
    - 数组中元素都在[0, 2^31)之间，因此可以将每个数表示为31位的二进制数
    - 由于要找到最大的x, 因此枚举每一位的时候，先判断这一位能否取到1， 否则取0
2. 这里选择字典树的方法

*/
struct Trie {
	Trie() {}
	//左子树表示0，右子树表示1
	Trie* left = nullptr;
	Trie* right = nullptr;
};
class Solution {
private:
	Trie* root = new Trie();
	static constexpr int HIGH = 30;

	void add(int num) {
		Trie* cur = root;
		for (int k = HIGH; k >= 0; --k) {
			int bit = (num >> k) & 1;
			if (bit == 0) {
				if (!cur->left)
					cur->left = new Trie();
				cur = cur->left;
			} else {
				if (!cur->right)
					cur->right = new Trie();
				cur = cur->right;
			}
		}
	}

	int check(int num) {
		Trie* cur = root;
		int x = 0;
		for (int k = HIGH; k >= 0; --k) {
			int bit = (num >> k) & 1;
			// bit == 0, num的第k个二进制位为0，应当往1的子节点走(?why
			if (bit == 0) {
				if (cur->right) {
					cur = cur->right;
					x = x * 2 + 1;
				} else {
					cur = cur->left;
					x = x * 2;
				}
			}
			// bit == 1, num的第k个二进制位为1，应当往0的子节点走(?why
			else {
				if (cur->left) {
					cur = cur->left;
					x = x * 2 + 1;
				} else {
					cur = cur->right;
					x = x * 2;
				}
			}
		}
		return x;
	}

public:
	int findMaximumXOR(vector<int>& nums) {
		int n = nums.size();
		int x = 0;
		for (int i = 1; i < n; ++i) {
			add(nums[i - 1]);
			// nums[i]看作a[i] a[j] = x ^ a[i]
			x = max(x, check(nums[i]));
		}
		return x;
	}
};
int main() { return 0; }