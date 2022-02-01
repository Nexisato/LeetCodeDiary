/*
LeetCode: 384 Shuffle an Array
Description:
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:
-Solution(int[] nums) : Initializes the object with the integer array nums.
-int[] reset()        : Resets the array to its original configuration and returns it.
-int[] shuffle()      : Returns a random shuffling of the array.

Constraints:
1 <= nums.length <= 200
-10^6 <= nums[i] <= 10^6
All the elements of nums are unique.
At most 5 * 10^4 calls will be made to reset and shuffle.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> arr;
    vector<int> origin;
public:
    Solution(vector<int>& nums) {
        this->arr.assign(nums.begin(),nums.end());
        this->origin = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr.clear();
        arr.assign(origin.begin(),origin.end());
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int N = arr.size();
        int randIdx = 0;
        //srand(time(0));
        for (int i = 0; i < N; i++) {
            randIdx = (rand() % (N - i)) + i;
            swap(arr[i], arr[randIdx]);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
    int N = 10;
    srand(time(0));
    while (N--) {
        int tmp = (rand() % 6);
        cout << tmp <<endl;
    }
    return 0;
}