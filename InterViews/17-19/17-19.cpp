/*
Missing Two LCCI
You are given an array with all the numbers from 1 to N appearing exactly once, except for two number that is missing. 
How can you find the missing number in O(N) time and 0(1) space?

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        int remain = sum;
        for (const auto& num : nums)
            remain -= num;
        



      
    }
};
int main() {



    return 0;
}