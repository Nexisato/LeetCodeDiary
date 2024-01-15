#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 需要构建一一映射
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> table;
        unordered_map<string, char> revtable;
        string word = "";
        vector<string> words;
        for (const auto& c : s) {
            if (c == ' ') {
                words.emplace_back(word);
                word = "";
                continue;
            }
            word += c;
        }
        words.emplace_back(word);
        if (words.size() != pattern.length()) return false;
        int idx = 0;
        for (const auto& c : pattern) {
            if (table.find(c) == table.end()) {
                table[c] = words[idx];
            } else {
                if (table[c] != words[idx]) return false;
            }
            ++idx;
        }
        idx = 0;
        for (const auto& word : words) {
            if (revtable.find(word) == revtable.end())
                revtable[word] = pattern[idx];
            else {
                if (revtable[word] != pattern[idx]) return false;
            }
            ++idx;
        }
        return true;
    }
};

int main() {
    return 0;
}