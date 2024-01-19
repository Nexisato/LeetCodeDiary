#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> table;
        for (auto a : s) {
            ++table[a];
            if (table[a] == 2)
                return a;
        }
        return s[0];       
    }
};
int main() {



    return 0;
}