/*
 * @Date: 2023-12-10 01:13:31
 * @Author: nexisato
 * @FilePath: /LeetCodeDiary/LeetCode/0189_旋转数组/189_旋转数组.cpp
 * @Description: 
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //超出时间限制!!
    void rotate_1(vector<int>& nums, int k) {
        if(k==0) return;
        int tmp=nums[nums.size()-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i]=nums[i-1];
        }
        nums[0]=tmp;
        rotate_1(nums,k-1);
            
    }
    void rotate(vector<int>& nums,int k){
        const int n = nums.size();
        if (n == 1) return;
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
    void Print(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it+=1){
            cout<<*(it)<<endl;
        }
    }
};

int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    Solution ss;
    ss.rotate(nums,3);
    ss.Print(nums);


    

    return 0;
}