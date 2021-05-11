/*
剑指Offer 40: 最小的K个数
@Description:
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 

Constraints:
0 <= k <= arr.length <= 10000
0 <= arr[i] <= 10000
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：使用最大堆
先向堆中存储k个元素
遍历数组剩余元素，遇到比堆顶小的则先出堆，再入堆
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int, vector<int>, less<int>> maxHeap;
        vector<int> res;
        int n = arr.size();
        int heap_size = 0;
        for (int i = 0; i < n; ++i) {
            if (heap_size < k) {
                maxHeap.push(arr[i]);
                heap_size++;
            }
            else {
                if (arr[i] < maxHeap.top()) {
                    maxHeap.pop();
                    maxHeap.push(arr[i]);
                }
            }
        }
        while (!maxHeap.empty()) {
            res.emplace_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }
};
int main() {

    return 0;
}