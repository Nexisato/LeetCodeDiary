/*
 * @Date: 2024-01-17 12:04:52
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/2744_Find_Max_Number_of_String_Pairs/2744.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int res = 0;
        unordered_set<string> st;
        for (auto word : words)
            st.insert(word);
        for (auto word : words) {
            if (st.find(word) == st.end())
                continue;
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (rev != word && st.find(rev) != st.end()) {
                ++res;
                st.erase(word);
                st.erase(rev);
            }
        }
        return res;
    }
};
int main() {

    return 0;
}