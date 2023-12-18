#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * 思路：
 * 这里是一个上凸函数的离散取值，所以可以用二分查找
 * 极值一定存在
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[mid + 1]) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};



int main() {
    return 0;
}