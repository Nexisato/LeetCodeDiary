/*
LeetCode 503: Next Greater Element II
@Description:
Given a circular array (the next element of the last element is the first element of the array),
print the Next Greater Number for every element. The Next Greater Number of a number x
is the first greater number to its traversing-order next in the array,
which means you could search circularly to find its next greater number.
If it doesn't exist, output -1 for this number.

Note: The length of given array won't exceed 10000.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：单调栈
1. 单调栈属于【被动】遍历的更新方式，栈内存放的是还没有经过更新得到答案的下标
2. 遍历nums数组，将当前下标存入栈内前，检查一下当前值能否作为栈顶位置的答案，若可以，则更新答案，并出栈
3. 因此选用单调递减栈
4. 由于该数组为循环数组，因此应当遍历两次，【可以对遍历下标取余转换】
*/
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int N = nums.size();
		vector<int> st, res(N, -1);
		for (int i = 0; i < 2 * N - 1; ++i) {
			while (!st.empty() && nums[st.back()] < nums[i % N]) {
				res[st.back()] = nums[i % N];
				st.pop_back();
			}
			st.emplace_back(i % N);
		}
		return res;
	}
};
int main() { return 0; }