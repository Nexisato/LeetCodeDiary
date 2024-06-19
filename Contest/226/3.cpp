/*
LeetCode 5667: Can you Eat Your Favorite Candy on Your Favorite Day?
Description:
You are given a (0-indexed) array of positive integers candiesCount where
candiesCount[i] represents the number of candies of the ith type you have. You are also
given a 2D array queries where queries[i] = [favoriteTypei, favoriteDayi, dailyCapi].

You play a game with the following rules:
-You start eating candies on day 0.
-You cannot eat any candy of type i unless you have eaten all candies of type i - 1.
-You must eat at least one candy per day until you have eaten all the candies.
Construct a boolean array answer such that answer.length == queries.length and answer[i]
is true if you can eat a candy of type favoriteTypei on day favoriteDayi without eating
more than dailyCapi candies on any day, and false otherwise. Note that you can eat
different types of candy on the same day, provided that you follow rule 2.

Return the constructed array answer.

Constraints:
1 <= candiesCount.length <= 10^5
1 <= candiesCount[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 3
0 <= favoriteTypei < candiesCount.length
0 <= favoriteDayi <= 10^9
1 <= dailyCapi <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
对于每一个询问，考虑两种极端情况：
每天按照上限吃，也无法在favoriteDayi之前吃完favoriteTypei之前的糖果
    包括刚好吃完的情形，因为我们还需要至少吃一个favoriteTypei类型的糖果
每天按照下限吃，也会在favoriteDayi之前吃完favoriteTypei以前的糖果
*/
class Solution {
public:
	vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
		vector<bool> res;
		int N = candiesCount.size();
		vector<long long> Sum(N + 1);
		for (int i = 1; i <= N; ++i)
			Sum[i] =
			    Sum[i - 1] + candiesCount[i - 1]; // Sum[i]表示Typei以前的所有糖果总和
		for (vector<int>& query : queries) {
			bool flag = true;
			int favType = query[0], favDay = query[1], dailyCap = query[2];
			long long minSum = favDay;
			long long maxSum = (long long)dailyCap * (favDay + 1);
			if (maxSum <= Sum[favType] || minSum >= Sum[favType + 1])
				flag = false;
			res.push_back(flag);
		}
		return res;
	}
};

int main() {
	vector<int> candiesCount = {
	    16, 38, 8,  41, 30, 31, 14, 45, 3,  2,  24, 23, 38, 30, 31, 17, 35, 4,  9,
	    42, 28, 18, 37, 18, 14, 46, 11, 13, 19, 3,  5,  39, 24, 48, 20, 29, 4,  19,
	    36, 11, 28, 49, 38, 16, 23, 24, 4,  22, 29, 35, 45, 38, 37, 40, 2,  37, 8,
	    41, 33, 8,  40, 27, 13, 4,  33, 5,  8,  14, 19, 35, 31, 8,  8};
	vector<int> query = {43, 1054, 49};
	vector<vector<int>> queries;
	queries.push_back(query);
	Solution ss;
	long long sum = 0;
	for (int count : candiesCount)
		sum += count;
	cout << candiesCount.size() << " " << sum << endl;
	vector<bool> res = ss.canEat(candiesCount, queries);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	return 0;
}