/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0121_Best_Time_Sell_Stack/121_Best_Time_Sell_Stack.cpp
 * @Description:
 */
/*
Description:
Say you have an array for which the ith element is the price of a given stock on
day i. If you were only permitted to complete at most one transaction (i.e., buy
one and sell one share of the stock), design an algorithm to find the maximum
profit. Note that you cannot sell a stock before you buy one.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// 思路：动态规划，设f(i)为第i天卖出可得的最大利润，由于f(i-1)=p[i-1]-minval
	//  f(i)=max(p[i]-p[i-1]+f(i-1),0)
	int maxProfit(vector<int>& prices) {
		if (!prices.size())
			return 0;
		int preF = 0, F = 0, maxVal = 0;
		for (int i = 1; i < prices.size(); i++) {
			F = max(preF + prices[i] - prices[i - 1], 0);
			maxVal = max(maxVal, F);
			preF = F;
		}
		return maxVal;
	}
	int maxProfit_dp(vector<int>& prices) {
		if (!prices.size())
			return 0;
		vector<int> dp(prices.size(), 0);
		int minVal = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			dp[i] = max(dp[i - 1], prices[i] - minVal);
			minVal = min(minVal, prices[i]);
		}
		return dp[prices.size() - 1];
	}
	// 思路：贪心算法
	int maxProfit_greedy(vector<int>& prices) {
		int minVal = INT32_MAX, maxP = 0;
		for (int i = 0; i < prices.size(); ++i) {
			minVal = min(minVal, prices[i]);
			maxP = max(maxP, prices[i] - minVal);
		}
		return maxP;
	}
};

int main() {
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	Solution ss;
	cout << ss.maxProfit(prices);
	/*for(vector<int>::iterator it=prices.begin();it<prices.end();it++)
	    cout<<*(it)<<endl;*/
	return 0;
}