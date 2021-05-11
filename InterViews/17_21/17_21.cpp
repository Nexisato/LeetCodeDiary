/*
LeetCode Interview: 17.21
@Description:
Imagine a histogram (bar graph). Design an algorithm to compute the volume of water it 
could hold if someone poured water across the top. You can assume that each histogram bar has width 1.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of water (blue section) are being trapped. Thanks Marcos for 
contributing this image!
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：总体积减去柱子体积就是水的容量

*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int l = 0, r = n - 1, totalVol = 0, curHeight = 1;
        int totalSum = accumulate(height.begin(), height.end(), 0);
        while (l <= r) {
            while (l <= r && height[l] < curHeight)
                l++;
            while (l <= r && height[r] < curHeight)
                r--;
            totalVol += (r - l) + 1;
            curHeight++;
        }
        return totalVol - totalSum;
    }
};
int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution ss;
    cout << ss.trap(nums);
    return 0;
}