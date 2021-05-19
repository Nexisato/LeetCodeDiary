/*
@Description:
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure 
that supports queries of two types:
- Add a positive integer to an element of a given index in the array nums2.
- Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value 
(0 <= i < nums1.length and 0 <= j < nums2.length).

Implement the FindSumPairs class:
- FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two 
- integer arrays nums1 and nums2.
- void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
- int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

Constraints:
1 <= nums1.length <= 1000
1 <= nums2.length <= 10^5
1 <= nums1[i] <= 10^9
1 <= nums2[i] <= 10^5
0 <= index < nums2.length
1 <= val <= 10^5
1 <= tot <= 10^9
At most 1000 calls are made to add and count each.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：仅仅枚举nums1即可
*/
class FindSumPairs {
private:
    vector<int> arr1, arr2;
    unordered_map<int, int> table;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->arr1 = nums1;
        this->arr2 = nums2;
        for (auto& num : nums2)
            ++table[num];
    }
    
    void add(int index, int val) {
        --table[this->arr2[index]];
        this->arr2[index] += val;
        ++table[this->arr2[index]];
    }
    
    int count(int tot) {
        int res = 0;
        for (auto& num : this->arr1) {
            if (table.find(tot - num) != table.end())
                res += table[tot - num];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
int main() {


    return 0;
}