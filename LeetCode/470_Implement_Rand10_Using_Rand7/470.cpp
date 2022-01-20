/*
LeetCode 470: Implement Rand10() Using Rand7()
@Description:
Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() 
that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), 
and you shouldn't call any other API. Please do not use a language's built-in random API.

Each test case will have one internal argument n, the number of times that your implemented function rand10() 
will be called while testing. Note that this is not an argument passed to rand10().

Follow up:
- What is the expected value for the number of calls to rand7() function?
- Could you minimize the number of calls to rand7()?
 
Constraints:
1 <= n <= 10^5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
/*
思路：拒绝采样 + 古典概型
(randX() - 1) * Y + randY() 可以等概率生成 [1, X * Y]中的数
*/
class Solution {
private:
    int rand7(){}
public:
    int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num % 10 + 1;
        }
    }
};
int main() {


    return 0;
}