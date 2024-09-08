#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;

/**
 * 假设 dp(x) 表示区间 (1~x) 内合法数的个数
 * dp_(l, r) = dp(r) - dp(l - 1)
 */
class Solution {
private:
    vector<int> nums;
    int dp(int maxNum) {
        vector<int> arr;
        while (maxNum > 0) {
            arr.push_back(maxNum % 10);
            maxNum /= 10;
        }
        int m = arr.size(), nums_l = nums.size(), res = 0;
        for (int i = m - 1, p = 1; i >= 0; --i, ++p) {
            int cur = arr[i];
            int l = 0, r = nums_l - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums[mid] <= cur) l = mid;
                else r = mid - 1;
            }
            // 二分寻找 nums[mid] <= cur 的最大下标
            if (nums[r] > cur)
                break;
            else if (nums[r] == cur) {  
                res += r * (int)pow(nums_l, (m - p));
                if (i == 0) ++res;
            } else {
                res += (r + 1) * (int)pow(nums_l, (m - p));
                break;
            }

        }
        for (int i = 1, last = 1; i < m; ++i) {
            int cur = last * nums_l;
            res += cur;
            last = cur;
        }
        return res;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        nums.resize(digits.size());
        for (int i = 0; i < digits.size(); ++i) {
            nums[i] = stoi(digits[i]);
        }
        sort(nums.begin(), nums.end());
        return dp(n);
    }
};

int main() {


    return 0;
}