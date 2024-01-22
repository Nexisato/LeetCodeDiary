/*
 * @Date: 2023-12-10 01:13:32
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0670-Maximum-Swap/670.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    思路：
    数据量比较小，可以直接遍历，升数据量的时候就需要用贪心
    */
    int maximumSwap(int num) {
        vector<int> digits;
        int originNum = num, copyNum = num;
        while (copyNum != 0) {
            digits.emplace_back(copyNum % 10);
            copyNum /= 10;
        }
        if (digits.size() == 1)
            return num;
        reverse(digits.begin(), digits.end());
        auto arrSum = ([&digits]() {
            int sum = 0;
            for (int i = 0; i < digits.size(); ++i) {
                sum *= 10;
                sum += digits[i];  
            }
            return sum;
        });
        int maxNum = arrSum();
        for (int i = 0; i < digits.size() - 1; ++i)
            for (int j = i + 1; j < digits.size(); ++j) {
                swap(digits[i], digits[j]);
                int tmp = arrSum();
                if (tmp > maxNum)
                    maxNum = tmp;
                swap(digits[i], digits[j]);     
            }

        return maxNum;
    }
    //Greedy
    int maximumSwap_greedy(int num) {
        string charArr = to_string(num);
        int n = charArr.size();
        int maxIdx = n - 1, idx1 = -1, idx2 = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (charArr[i] > charArr[maxIdx])
                maxIdx = i;
            else if (charArr[i] < charArr[maxIdx]) {
                idx1 = i;
                idx2 = maxIdx;
            }
        }
        if (idx1 >= 0) {
            swap(charArr[idx1], charArr[idx2]);
            return stoi(charArr);
        }
        else
            return num;
    }

};
int main() {


    int num = 1;
    Solution *ss = new Solution();
    int res = ss->maximumSwap(num);
    cout << res << endl;


    return 0;
}