#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 
 * 
 * 
 */
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int qL = queries.size(), m = pattern.length();
        vector<bool> res(qL, true);
        // for (auto query : queries) {
        //     int n = query.length();
        //     int qPtr = 0, pPtr = 0;
        //     while (qPtr < n && pPtr < m) {
        //         if (query[qPtr] == pattern[pPtr]) {
        //             ++qPtr;
        //             ++pPtr;
        //         } else if (query[qPtr] >= 'a')
        //             ++qPtr;
        //         else
        //             break;
        //     }
        // }
        for (int i = 0; i < qL; ++i) {
            int p = 0;
            for (auto c : queries[i]) {
                if (p < pattern.size() && pattern[p] == c)
                    ++p;
                else if (isupper(c)) {
                    res[i] = false;
                    break;
                }
            }
            if (p < pattern.size()) //最后 pattern 中有未被遍历到的
                res[i] = false;
        }
        return res;
    }
};
int main() {

    return 0;
}