#include <bits/stdc++.h>
using namespace std;

/*
Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers.
Return the subarray. If there are more than one answer, return the one which has the smallest index of its left endpoint. 
If there is no answer, return an empty arrary.
*/
/*
前缀和 + 哈希表
1. 字符看作 1 ，数字看作 -1，即求最长的子数组，使得和为 0 
2. maxL 和 startI 分别记录满足条件的子数组的长度和左端点的位置；
-- 若当前位置前缀和 sum 在哈希表中存在，记录 s 第一次出现的位置为 j ，则 [j+1, i] 的子数组和为 0，若 max < i - j, 更新，startI = j + 1 
-- 否则，当前前缀和 ssum 为键，i 作为值，存在哈希表中
*/

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        unordered_map<int, int> vis{{0, -1}}; // key 为 和，value 为 下表
        int sum = 0, maxL = 0, startI = 0;
        for (int i = 0; i < n; i++) {
            sum += array[i][0] >= 'A' ? 1 : -1;
            if (vis.count(sum)) {
                int j = vis[sum];
                if (maxL < i - j) {
                    maxL = i - j;
                    startI = j + 1;
                }
            } else {
                vis[sum] = i;
            }
        }
        return vector<string> (array.begin() + startI, array.begin() + startI + maxL);
    }
};
int main() {
    vector<string> array({"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"});
    Solution ss;
    vector<string> res = ss.findLongestSubarray(array);
    for (auto a : res)
        cout << a << "  ";
    cout << endl;



    return 0;
}