/*
@Description:

*/
#include <bits/stdc++.h>
using namespace std;

/*
思路：
*/
class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        unordered_map<char, int> table;
        for (auto& c : s)
            ++table[c];
        if (n % 2 && abs(table['0'] - table['1']) != 1)
            return -1;
        else if (n % 2 == 0 && table['0'] != table['1'])
            return -1;
        
        


    }
};
int main() {


    return 0;
}