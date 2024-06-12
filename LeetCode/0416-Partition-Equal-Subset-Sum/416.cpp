#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;

        return false;
    }
};
int main() {


    return 0;
}