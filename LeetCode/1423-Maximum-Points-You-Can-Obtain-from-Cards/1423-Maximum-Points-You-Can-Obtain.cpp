/*
LeetCode 1423: Maximum Points You Can Obtain from Cards
@Description:
There are several cards arranged in a row, and each card has an associated number of
points  The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row.
You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can
obtain.

Constraints:
1 <= cardPoints.length <= 10^5
1 <= cardPoints[i] <= 10^4
1 <= k <= cardPoints.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：滑动窗口
由于只能从开头或末尾拿k张卡牌，因此中间一定剩下n-k张卡牌
因此只需要滑动窗口计算中间 n-k 张卡牌的最小值
*/
class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int left = 0, right = cardPoints.size() - k;
		int sum = accumulate(cardPoints.begin(), cardPoints.begin() + right, 0);
		int minSum = sum;
		while (right < cardPoints.size()) {
			sum += cardPoints[right] - cardPoints[left];
			++right;
			++left;
			minSum = min(minSum, sum);
		}
		return accumulate(cardPoints.begin(), cardPoints.end(), 0) - minSum;
	}
};
int main() { return 0; }