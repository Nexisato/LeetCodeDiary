/*
LeetCode 179: Largest Number
@Description:
Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：字典序排序
对于nums数组中的任意两个值a,b，我们无法从常规角度直接比较他们的大小/先后关系
根据结果，若ab好于ba，则选用ab
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums)
            strs.emplace_back(to_string(num));

        //lambda function: cmp as dict order
        auto cmp = [](string a, string b) {
            return a + b > b + a;
        };

        sort(strs.begin(), strs.end(), cmp);
        /*
        string res = "";
        for (auto& c : strs)
            res += c;
        */
        // stringstream 格式
        stringstream ss;
        for (auto c : strs)
            ss << c;
        string res= ss.str();
        //
        if (res[0] == '0')
            return "0";
        return res;
    }
};
int main() {


    return 0;
}