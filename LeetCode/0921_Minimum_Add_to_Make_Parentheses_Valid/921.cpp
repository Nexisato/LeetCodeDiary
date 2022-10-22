#include <bits/stdc++.h>
using namespace std;
/*
栈括号匹配
*/
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int res = 0, cnt = 0;
        vector<int> st;
        for (const auto a : s) {
            if (a == '(') 
                st.emplace_back(a);
            else {
                if (!st.empty())
                    st.pop_back();
                else {
                    ++res;
                }
            }
        }
        res += st.size();
        return res;

    }
};
int main() {

    return 0;
}