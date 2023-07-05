#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  // 思路：此题巨坑！！！！！！！！！
  // 注意数码中有9应当进位，全9的数码应当增加一位1
  vector<int> plusOne(vector<int> &digits) {
    for (int idx = digits.size() - 1; idx >= 0; idx--) {
      digits[idx]++;
      if (digits[idx] == 10)
        digits[idx] = 0;
      else
        return digits; // 此处很巧
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }

  void Print(vector<int> &nums) {
    for (auto it = nums.begin(); it != nums.end(); it += 1) {
      cout << *(it) << endl;
    }
  }
};

int main() {
  vector<int> nums = {9, 9, 9};
  Solution ss;
  ss.plusOne(nums);
  ss.Print(nums);
  return 0;
}