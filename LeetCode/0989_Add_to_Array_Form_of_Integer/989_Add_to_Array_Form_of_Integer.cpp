/*
LeetCode: 989 Add to Array Form of Integer
Dscription:
For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.

Note：
1 <= A.length <= 10000
0 <= A[i] <= 9
0 <= K <= 10000
If A.length > 1, then A[0] != 0
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：逐位相加
1. A, K的数码长度不定，因此都需要遍历
2. 相加得到的进位值可直接加在K上，免去重复检查所需要的时间开销
*/
class Solution {
public:
/*
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> K_buck;
        while ( K != 0) {
            K_buck.push_back(K % 10);
            K /= 10;
        }
        reverse(K_buck.begin(), K_buck.end());
        vector<int> res;
        int c = 0;
        while (!A.empty() && !K_buck.empty()) {
            int tmp = K_buck.back() + A.back() + c;
            c = (tmp >= 10) ? 1 : 0;
            tmp = (tmp >= 10) ? (tmp - 10) : tmp;
            res.push_back(tmp);
            A.pop_back();
            K_buck.pop_back();
        }
        if (!A.empty()) {
            for (int i = A.size() - 1; i >= 0; i--) {
                A[i] += c;
                if (A[i] < 10)  { c = 0; break;}
                c = 1; 
                A[i] -= 10;
            }
            reverse(res.begin(), res.end());
            A.insert(A.end(), res.begin(), res.end());
            if (c) A.insert(A.begin(), 1);
            return A;
        }
        if (!K_buck.empty()) {
            for (int i = K_buck.size() - 1; i >= 0; i--) {
                K_buck[i] += c;
                if (K_buck[i] < 10)  { c = 0; break;}
                c = 1; 
                K_buck[i] -= 10;
            }
            K_buck.insert(K_buck.end(), res.begin(), res.end());
            if (c) {K_buck.push_back(1), reverse(K_buck.begin(), K_buck.end());}
            return K_buck;
        }
        if (c == 1) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }*/
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res;
        int N = A.size();
        for (int i = N - 1; i >= 0; i--) {
            int tmp = A[i] + K % 10;
                K /= 10;
                if (tmp >= 10) {
                    tmp -= 10;
                    K++;//将进位转移到待加整数中
                }
            res.push_back(tmp);
        }
        while (K != 0) {
            res.push_back(K % 10);
            K /= 10;
        } 

        reverse(res.begin(), res.end());
        return res;
    }
};
/*
思路：
将K加入数组最低位：
    ex. A = [1, 2, 3], K = 912
    1. [1, 2, 3 + 912], 最低位取模，再除以10转移到高一位
    2. [1, 91 + 2， 5]
    3. [1 + 9, 3, 5]
    4. [1, 0, 3, 5]
*/
class Solution2 {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        vector<int> res;
        int N = A.size();
        for (int i = N - 1; i >= 0; i--) {
            K += A[i];
            res.push_back(K % 10);
            K /= 10;
        }
        while (K != 0) {
            res.push_back(K % 10);
            K /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution ss;
    vector<int> A = {9,9,9} ;
    int K = 1;
    vector<int> res = ss.addToArrayForm(A, K);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] <<" ";
    return 0;
}