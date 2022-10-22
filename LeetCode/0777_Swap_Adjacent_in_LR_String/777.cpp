#include <bits/stdc++.h>
using namespace std;
/*
思路：
L R的相对位置不会变
XL->LX，可以看作 L 跨过 X 左移
RX->XR，可以看作 R 跨过 X 右移
*/

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length();
        int i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') ++i;
            while (j < n && end[j] == 'X') ++j;
            if (i == n || j == n) 
                return i == j;
            if (start[i] != end[j])
                return false;
            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;
            ++i; ++j;
        }
        return i == j;
        
    }
};
int main() {
    string start = "RXXLRXRXL", end = "XRLXXRRLX";
    Solution *ss;
    cout << ss->canTransform(start, end) << endl;

    return 0;
}