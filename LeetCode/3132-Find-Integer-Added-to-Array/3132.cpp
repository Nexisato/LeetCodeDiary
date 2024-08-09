#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 需要在 判断差值的基础上弹出两个数
class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // nums1 前三个元素必定有一个是最小值
        for (int k = 2; k >= 0; --k) {
            int min_val = nums1[k];
            int d = nums2[0] - min_val;
            for (int i = k, j = 0; i < nums1.size(); ++i) {
                if (nums1[i] + d == nums2[j]) ++j;
                if (j == nums2.size()) return d;
            }
        }
        return nums2[0] - nums1[0];
    }
};

int main() {



    return 0;
}