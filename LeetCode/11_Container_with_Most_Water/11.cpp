/*
LeetCode 11: Container With Most Water
@Description:
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate 
(i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) 
and (i, 0). Find two lines, which, together with the x-axis forms a container, 
such that the container contains the most water.

Notice that you may not slant the container.

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：双指针
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};
int main() {


    return 0;
}