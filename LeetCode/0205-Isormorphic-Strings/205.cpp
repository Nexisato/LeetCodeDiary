/*
 * @Date: 2024-01-13 23:49:52
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0205_Isormorphic_Strings/205.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> table1, table2;
        for (const auto& c : s) 
            table1[c]++;
        for (const auto& c : t)
            table2[c]++;
        if (table1.size() != table2.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (table1[s[i]] != table2[t[i]]) return false;
        }
        // 先比较长度，再比较每个字符出现的次数，最后比较字符映射
        unordered_map<char, char> mapping;
        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i], c2 = t[i];
            if (mapping.count(c1)) {
                if (mapping[c1] != c2) return false;
            } else {
                mapping[c1] = c2;
            }
        }
        return true;
    }
};
int main() {

    return 0;
}