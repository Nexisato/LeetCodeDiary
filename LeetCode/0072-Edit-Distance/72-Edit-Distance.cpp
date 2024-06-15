/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0072_Edit_Distance/72_Edit_Distance.cpp
 * @Description:
 */
/*
LeetCode: 72 Edit Distance
Description:
Given two strings word1 and word2,
return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
思路：
1. 确定dp数组和下标的含义
dp[i][j]表示长为i的字符串word1和长为j的字符串word2的编辑距离dp[i][j]
2. 确定递推公式
    · if (word1[i - 1] == word2 [j - 1])
            不操作：dp[i][j] = dp[i - 1][j - 1]
    · if (word1[i - 1] != word2 [j - 1])
        增：dp[i][j] = dp[i][j - 1] + 1，相当于word2[j - 1]匹配
        删：dp[i][j] = dp[i - 1][j] + 1，拿掉word1[i - 1]继续匹配
        改：dp[i][j] = dp[i - 1][j - 1] + 1
3. dp数组初始化：一个字符串长度为0而另一个不为0，做添加操作即可
4. 确定遍历顺序：左方、上方、左上方
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		for (int i = 0; i <= m; i++)
			dp[i][0] = i;
		for (int i = 0; i <= n; i++)
			dp[0][i] = i;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (word1[i - 1] == word2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		return dp[m][n];
	}
};
int main() { return 0; }
