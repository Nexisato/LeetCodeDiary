/*
LeetCode: Chalkboard XOR Game
@Description:

We are given non-negative integers nums[i] which are written on a chalkboard.  
Alice and Bob take turns erasing exactly one number from the chalkboard, with Alice starting first.  
If erasing a number causes the bitwise XOR of all the elements of the chalkboard to become 0, 
then that player loses.  (Also, we'll say the bitwise XOR of one element is that element itself, 
and the bitwise XOR of no elements is 0.)

Also, if any player starts their turn with the bitwise XOR of all the elements of the 
chalkboard equal to 0, then that player wins.

Return True if and only if Alice wins the game, assuming both players play optimally.

Notes:
1 <= N <= 1000. 
0 <= nums[i] <= 2^16.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：
可以证明，数组长度为偶数时，先手必定获胜
反设在Alice擦掉一个数字后不能获胜，找不到任何元素使得剩余数字异或结果不等于0，
即，Alice先手擦掉数字后，删掉任何一个数，剩余数异或结果都是0，即S[i] = 0
考虑S != 0的情况
S[i] ^ nums[i] = S
0 = s[0] ^ ... ^ S[n - 1] = 0 <=> (S ^ nums[0]) ^ (S ^ nums[1]) ^ ...^ (S ^ nums[n - 1]) = 0
n为偶数，可以合并为 S ^ 0 = 0，这样Alice开头即可获胜，矛盾

因此，Alice获胜仅有两种条件
- n % 2 == 0
*/
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        for (auto& num : nums)
            tot ^= num;
        return n % 2 == 0 || tot == 0;
    }
};
int main() {


    return 0;
}