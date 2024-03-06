/*
 * @Date: 2024-01-29 11:15:35
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0049-Group-Anagrams/49.cpp
 * @Description:
 */
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 时间复杂度稍高
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        auto isAnagram = [](string &s1, string &s2) -> bool {
            if (s1.length() != s2.length())
                return false;
            int count[26] = {0};
            for (int i = 0; i < s1.length(); ++i) {
                count[s1[i] - 'a']++;
                count[s2[i] - 'a']--;
            }
            for (int i = 0; i < 26; ++i)
                if (count[i] != 0)
                    return false;
            return true;
        };
        for (auto &str : strs) {
            bool flag = false;
            for (auto &group : res) {
                if (isAnagram(str, group[0])) {
                    flag = true;
                    group.push_back(str);
                    break;
                }
            }
            if (!flag) {
                vector<string> group;
                group.push_back(str);
                res.push_back(group);
            }
        }
        return res;
    }
    // 哈希法，tricks 稍多
    vector<vector<string>> groupAnagrams_hash(vector<string> &strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        vector<vector<string>> res;
        // 这里一定要是常量引用
        auto arrHash = [fn = hash<int>{}](const array<int, 26> &count) -> size_t {
            return accumulate(count.begin(), count.end(), 0u,[&](size_t acc, int num) { 
                return (acc << 1) ^ fn(num); 
            });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrHash)> table(0, arrHash);
        for (auto &str : strs) {
            array<int, 26> count{};
            for (auto &c : str)
                count[c - 'a']++;
            table[count].push_back(str);
        }
        for (auto &[_, group] : table) {
            res.push_back(group);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams_table(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> table;
        for (auto&& str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            table[s].push_back(s);
        }
        for (auto&& kv : table) {
            res.push_back(kv.second);
        }
        return res;
    }
};

int main() { return 0; }