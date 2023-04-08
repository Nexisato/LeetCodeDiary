/*
LeetCode 349: Intersection of Two Arrays
@Description:
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must be unique and you may return the result in any order.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：Set + 哈希表（等效于两个set)
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // int n1 = nums1.size(), n2 = nums2.size();
        // vector<int> res;
        // unordered_map<int, int> table;
        // set<int> appear;
        // for (auto num  : nums1)
        //     appear.insert(num);
        // for (auto num : nums2)
        //     if (appear.count(num) && table[num] == 0) {
        //         res.emplace_back(num);
        //         ++table[num];
        //     }
        // return res;

        // 两个 unordered_set 即可
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_set<int> res_set;
        unordered_set<int> table(nums1.begin(), nums1.end());
        for (auto num : nums2) {
            if (table.count(num))
                res_set.insert(num);
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};
int main() {

    return 0;
}