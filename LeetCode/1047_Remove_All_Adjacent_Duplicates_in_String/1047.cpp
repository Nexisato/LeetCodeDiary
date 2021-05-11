/*
LeetCode: 1047 Remove All Adjacent Duplicates in a String
@Description:
Given a string S of lowercase letters, a duplicate removal consists of choosing 
two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  
It is guaranteed the answer is unique.

Note:
1 <= S.length <= 20000
S consists only of English lowercase letters.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：栈
*/
class Solution {
public:
    string removeDuplicates(string S) {
        string res;
        for (char c : S) {
            if (!res.empty() && c == res.back()) {
                res.pop_back();
            }
            else
                res.push_back(c);
        }
        return res;
    }
};
int main() {

    return 0;
}