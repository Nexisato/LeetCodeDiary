/*
LeetCode 852: Peak Index in a Mountain Array
@Description:

Let's call an array arr a mountain if the following properties hold:
- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... arr[i-1] < arr[i]
    - arr[i] > arr[i+1] > ... > arr[arr.length - 1]
Given an integer array arr that is guaranteed to be a mountain, return any i such that 
arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

Constraints:
3 <= arr.length <= 10^4
0 <= arr[i] <= 10^6
arr is guaranteed to be a mountain array.

Follow up: Finding the O(n) is straightforward, could you find an O(log(n)) solution?
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分递归查找最大值

*/
class Solution {
private:
    int maxInterval(vector<int>& arr, int l, int r) {
        if (l >= r)
            return l;
        int mid = l + (r - l) / 2;
        int lMax = maxInterval(arr, l, mid - 1), rMax = maxInterval(arr, mid + 1, r);
        int res = (arr[mid] >= arr[lMax]) ? mid : lMax;
        res = (arr[res] >= arr[rMax]) ? res : rMax;
        return res; 
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int mid = -1, maxElem = -1;
        return maxInterval(arr, l, r);
    }
};
int main() {

    return 0;
}