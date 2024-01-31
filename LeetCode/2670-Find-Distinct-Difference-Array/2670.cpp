#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto& num : nums) ++cnt[num];
        unordered_set<int> cur;
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            cur.insert(nums[i]);
            --cnt[nums[i]];
            if (cnt[nums[i]] == 0) cnt.erase(nums[i]);
            diff[i] = cur.size() - cnt.size();
        }

        return diff;
    }
};
int main() {

    return 0;
}