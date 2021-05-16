/*
LeetCode 1310: XOR Queries of a Subarray
@Description:
Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], for each query 
i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.
 
Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 10^9
1 <= queries.length <= 3 * 10^4
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] < arr.length
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：仿照前缀和数组，构造"异或和"数组
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), L = queries.size();
        vector<int> sumXOR(n);
        sumXOR[0] = arr[0];
        for (int i = 1; i < n; ++i) 
            sumXOR[i] = arr[i] ^ sumXOR[i - 1];
        vector<int> res(L);
        for (int i = 0; i < L; ++i) {
            int l = queries[i][0], r = queries[i][1];
            if (l == r) 
                res[i] = arr[l];
            else if (l == 0)
                res[i] = sumXOR[r];
            else
                res[i] = sumXOR[r] ^ sumXOR[l - 1];
        }
        return res;
    }
};
int main() {


    return 0;
}