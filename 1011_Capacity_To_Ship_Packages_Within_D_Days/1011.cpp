/*
LeetCode 1011: Capacity To Ship Packages Within D Days
@Description:
A conveyor belt has packages that must be shipped from one port to another within D days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on 
the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within D days.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分查找
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int maxW = *max_element(weights.begin(), weights.end());
        int Sum = accumulate(weights.begin(), weights.end(), 0);
        //Check if capacity 'mid' satisfy the D-days requirement
        auto check = [&](int mid) {
            int cnt = 1, curW = 0;
            for (auto& w : weights) {
                curW += w;
                if (curW > mid) {
                    curW = w;
                    cnt++;
                }
            }
            return cnt <= D;
        };

        int low = maxW, high = Sum;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return high;
    }
};
int main() {


    return 0;
}