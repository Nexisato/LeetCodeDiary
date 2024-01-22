/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0167-Two-SumII/167-Two-SumII.cpp
 * @Description: 
 */
/*
LeetCode 167: TwoSum II - Input Array is Sorted
@Description:
Given an array of integers numbers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

Return the indices of the two numbers (1-indexed) as an integer array answer of size 2, 
where 1 <= answer[0] < answer[1] <= numbers.length.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Constraints:
2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers is sorted in increasing order.
-1000 <= target <= 1000
Only one valid answer exists.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
思路：

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() -1;
        while (left < right) {
            int lVal = numbers[left], rVal = numbers[right];
            int sum = lVal + rVal;
            if (sum < target)
                while (left < right && numbers[left] == lVal)
                    left++;
            else if (sum > target)
                while (left < right && numbers[right] == rVal)
                    right--;
            else 
                return {left + 1, right + 1};
        }
        return {};
    }
};
int main() {

    return 0;
}