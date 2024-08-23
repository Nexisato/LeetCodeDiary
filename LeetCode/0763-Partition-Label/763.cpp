#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int table[26] = {0};
        const int n = s.length();
        for (int i = 0; i < n; ++i) {
            table[s[i] - 'a'] = i;
        }
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            r = max(r, table[s[i] - 'a']);  // 这个区间内所有的元素的最右
            if (i == r) {
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        
        return res;
    }
};


int main() {


    return 0;
}