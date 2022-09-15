#include <bits/stdc++.h>
using namespace std;
/*
思路：找规律画状态机
注意观察：i和i+6的灯泡状态必然相同，因此只需要观察前6盏灯的状态。
6k + 1 受到开关 1,3,4的影响；
6k + 2 受到开关 1,2 的影响；
6k + 3 受到开关 1,3 的影响；
6k + 4 受到开关 1,2,4 的影响；
6k + 5 受到开关 1,3 的影响；
6k + 6 受到开关 1,2 的影响；
进一步，只需要看前4盏灯；
设按4类按钮的次数分别为 ： a, b , c, d
6k+1: (a + c + d) % 2;
6k+2: (a + b) % 2;
6k+3: (a + c) % 2;
6k+4: (a + b + d) % 2;
通过前3盏灯即可确定第4盏灯的状态，因此只需要看前3盏灯即可
*/
class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses == 0)
            return 1;
        if (n == 1)
            return 2;
        else if (n == 2)
            return presses == 1 ? 3 : 4;
        else
            return presses == 1 ? 4 : presses == 2 ? 7 : 8;

    }
};
int main() {


    return 0;
}