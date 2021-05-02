/*
LeetCode 220: Contains Duplicate III
@Description:
Given an integer array nums and two integers k and t, return true if there 
are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

Constraints:
0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 104
0 <= t <= 231 - 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：待Reveiw

*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> st;
        for (int i = 0; i < nums.size(); i++) {
            auto lb = st.lower_bound((long)nums[i] - t);
            if (lb != st.end() && *lb <= (long)nums[i] + t) 
                return true;
            st.insert(nums[i]);
            if (i >= k) st.erase(nums[i - k]);
        }
        return false;

    }
};
int main() {


    return 0;
}