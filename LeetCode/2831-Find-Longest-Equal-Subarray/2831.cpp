#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, vector<int>> table;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            table[nums[i]].push_back(i);
        }
        for (auto& [num, indices] : table) {
            int left = 0;
            for (int right = 0; right < indices.size(); ++right) {
                while (indices[right] - indices[left] - (right - left) > k) {
                    ++left;
                }
                res = max(res, right - left + 1);
            }
        }

        return res;
    }
};
int main() {


    return 0;
}