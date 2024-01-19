#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> table;
        for (int i = 0; i < n - 1; ++i) {
            if (++table[nums[i] + nums[i + 1]] > 1)
                return true;
        }
        return false;
    }
};
int main() {


    return 0;
}