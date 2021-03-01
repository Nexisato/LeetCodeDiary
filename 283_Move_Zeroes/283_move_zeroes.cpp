#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //思路1：双指针法
    //用一个快速指针遍历整个数组，用慢指针记录非零元素
    void moveZeroes_1(vector<int>& nums) {
        int slowPtr=0;
        for(int fastPtr=0;fastPtr<nums.size();fastPtr++){
            if(nums[fastPtr]!=0)
                nums[slowPtr++]=nums[fastPtr];
        }
        for(int i=slowPtr;i<nums.size();i++)
            nums[i]=0;
    }
    //思路2：双指针-交换元素法
    //用一个快速指针遍历整个数组，若不为0则与慢指针交换
    void moveZeroes(vector<int>& nums){
        int slowPtr=0;
        for(int fastPtr=0;fastPtr<nums.size();fastPtr++)
            if(nums[fastPtr]!=0)
                swap(nums[slowPtr++],nums[fastPtr]);

    }
    void Print(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it+=1){
            cout<<*(it)<<endl;
        }
    }
};

int main(){
    vector<int> nums={0,1,0,3,12};
    Solution ss;
    ss.moveZeroes_1(nums);
    ss.Print(nums);


    return 0;
}
