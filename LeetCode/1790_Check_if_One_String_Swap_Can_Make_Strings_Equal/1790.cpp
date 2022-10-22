#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        /**
        if (s1 == s2)
            return true;
        for (int i = 0; i < s2.length() - 1; ++i)
            for (int j = i + 1; j < s2.length(); ++j) {
                swap(s2[i], s2[j]);
                if (s1 == s2)
                    return true;
                swap(s2[i], s2[j]);
            }
        return false;
        */
       int n = s1.length(), a = -1, b = -1;
       for (int i = 0; i < n; ++i) {
            if (s1[i] == s2[i])
                continue;
            if (a == -1)
                a = i;
            else if (b == -1)
                b = i;
            else 
                return false;
       }
       if (a == -1) return true;
       if (b == -1) return false;
       return s1[a] == s2[b] && s1[b] == s2[a];
    }
};
int main() {



    return 0;
}