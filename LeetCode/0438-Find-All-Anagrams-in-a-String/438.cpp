/*
 * @Date: 2024-02-03 11:08:32
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0438-Find-All-Anagrams-in-a-String/438.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 30 和 438 的区别在于 30 是找到所有的子串，而 438 是找到所有的字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.length(), len = p.length();
        unordered_map<char, int> table;
        for (auto& c : p)
            table[c]++;
        unordered_map<char, int> window;
        int count = 0;
        for (int left = 0, right = 0; right < n;) {
            char cur = s[right];
            ++right;
            if (table.count(cur)) {
                ++window[cur];
                ++count;
                while (window[cur] > table[cur]) {
                    --window[s[left]];
                    ++left;
                    --count;
                }
                if (count == len) {
                    res.push_back(left);
                }
            } else {
                window.clear();
                count = 0;
                left = right;
            }
        }
        return res;
    }
};
int main() {

    return 0;
}