/*
LeetCode 1744:
@Description:
You are given a (0-indexed) array of positive integers candiesCount where candiesCount[i] represents the number 
of candies of the ith type you have. You are also given a 2D array queries 
where queries[i] = [favoriteTypei, favoriteDayi, dailyCapi].

You play a game with the following rules:
- You start eating candies on day 0.
- You cannot eat any candy of type i unless you have eaten all candies of type i - 1.
- You must eat at least one candy per day until you have eaten all the candies.

Construct a boolean array answer such that answer.length == queries.length and answer[i] is true 
if you can eat a candy of type favoriteTypei on day favoriteDayi without eating more than dailyCapi candies on any day, 
and false otherwise. Note that you can eat different types of candy on the same day, provided that you follow rule 2.

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
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<bool> canEat(std::vector<int>& candiesCount, std::vector<std::vector<int>>& queries) {
        std::vector<bool> res;
        int N = candiesCount.size();
        std::vector<long long> Sum(N + 1);
        for (int i = 1; i <= N ; ++i)
            Sum[i] = Sum[i - 1] + candiesCount[i - 1]; 
        for (std::vector<int>& query : queries) {
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

    return 0;
}