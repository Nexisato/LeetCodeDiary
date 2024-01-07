#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/**
 * 思路：依然是二分
 * 找到每一行的最大值
 * 如果这一行的最大值大于下一行的最大值，那么峰值所在行一定在这行及以上
 * 反之，峰值所在行一定在下一行及以下
 * 
 * 二分查找结束后，峰值所在行已经确定，只需要再找到这一行的最大值即可
*/
class Solution {
private:
    int indexOfMaxElement(const vector<int>& arr) {
        return max_element(arr.begin(), arr.end()) - arr.begin();
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();
        vector<int> res(2, -1);
        int left = 0, right = m - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int maxIdx = indexOfMaxElement(mat[mid]);
            if (mat[mid][maxIdx] > mat[mid + 1][maxIdx]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        res[0] = left;
        res[1] = indexOfMaxElement(mat[left]);

        return res;
    }
};

int main() {


    return 0;
}