/*
Description:
The count-and-say sequence is a sequence of digit strings defined by the
recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from
countAndSay(n-1), which is then converted into a different digit string. To
determine how you "say" a digit string, split it into the minimal number of
groups so that each group is a contiguous section all of the same character.
Then for each group, say the number of characters, then say the character.
To convert the saying into a digit string, replace the counts with a number
and concatenate every saying.

For example, the saying and conversion for digit string "3322251":

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  // 思路：在递归的基础上建立空字符串，然后根据出现次数进行字符串拼接
  string countAndSay(int n) {
    if (n == 1)
      return "1";
    string previous = countAndSay(n - 1), res = "";
    int count = 1;
    for (int i = 0; i < previous.length(); i++) {
      if (previous[i] == previous[i + 1]) {
        count++;
      } else {
        res += to_string(count) + previous[i];
        count = 1;
      }
    }
    return res;
  }
};

int main() {
  Solution ss;
  cout << ss.countAndSay(6) << endl;
  return 0;
}
