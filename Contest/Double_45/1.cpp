/*
LeetCode 5657: Sum of Unique Elements
@Description:
You are given an integer array nums. The unique elements of an array are the elements 
that appear exactly once in the array.

Return the sum of all the unique elements of nums.

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：签到题emmm

*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> table(101, 0);
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }
        int sum = 0;
        for (int i = 1; i <= 100; i++)
            if (table[i] == 1)
                sum += i;
        return sum;
    }
};
int main() {

    return 0;
}