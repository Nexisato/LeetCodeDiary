/*
@Description:

*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
*/
class FindSumPairs {
private:
    vector<int> arr1, arr2;
    unordered_map<int, set<pair<int, int>>> table;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1.clear();
        arr2.clear();
        arr1 = nums1;
        arr2 = nums2;
        int n1 = arr1.size(), n2 = arr2.size();
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < n2; ++j) {
                int sum = arr1[i] + arr2[j];
                table[sum].insert(i, j);
            }
    }
    
    void add(int index, int val) {
        arr2[index] += val;
        
    }
    
    int count(int tot) {

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