/*
LeetCode: 1128 Number of Equivalent Domino Pairs
Description:
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] 
if and only if either (a==c and b==d), or (a==d and b==c)
- that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
and dominoes[i] is equivalent to dominoes[j].

Constraints:
1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
1. 暴力遍历必定超时
2. 二元组表示 + 计数
    · 不妨让每一个二元对都表示为指定的格式：第一维不大于第二维，即(x, y)：x <= y
    · 二维映射为一维，即 (x, y) -> 10x + y 【由于 0 <= x,y <= 9】
    这样就无需使用hashmap，使用一个空间为100的数组一一对应即可

*/
class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		vector<int> sum(100, 0);
		int count = 0;
		int N = dominoes.size();
		for (auto& arr : dominoes) {
			int val = (arr[0] <= arr[1]) ? (arr[0] * 10 + arr[1]) : (arr[0] + arr[1] * 10);
			count += sum[val]; //顺序不可替换，即 val 第二次出现时才开始计数
			sum[val]++;
		}
		return count;
	}
};
int main() { return 0; }