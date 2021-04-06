/*
LeetCode 781: Rabbits in Forest
@Description:
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) 
tell you how many other rabbits have the same color as them. Those answers are placed in an array.

Return the minimum number of rabbits that could be in the forest.

Note:
answers will have length at most 1000.
Each answers[i] will be an integer in the range [0, 999].
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
看见x只同色的兔子有y个
则至少有 ceil(y /(x + 1)) * (x + 1)
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if (n == 0)
            return 0;
        int res = 0;
        unordered_map<int, int> table;
        for (const auto& answer : answers)
            table[answer]++;
        for (auto it = table.begin(); it != table.end(); ++it) {
            res += ((it->first + it->second) / (it->first + 1)) * (it->first + 1);
        }
        return res;
    }
};
int main() {

    return 0;
}