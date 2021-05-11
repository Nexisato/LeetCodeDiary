#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1;
        int size=nums.size();
        for(int i=1;i<size;++i)
            if(nums[i]!=nums[i-1]){
                nums[count++]=nums[i];
            }
        nums.erase(nums.begin()+count,nums.end());
        return count;
    }
    void Print(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin();it!=nums.end();it+=1){
            cout<<*(it)<<endl;
        }
    }
    int removeDuplicates_faster(vector<int>& nums){
        if(nums.empty()) return 0;
        int slowPtr=0;
        for(vector<int>::size_type fastPtr=0;fastPtr<(nums.size()-1);fastPtr++){
            if(nums[fastPtr]!=nums[fastPtr+1])
                nums[++slowPtr]=nums[fastPtr+1];
        }
        return slowPtr+1;
    }

};

int main(){
    Solution ss;
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<ss.removeDuplicates_faster(nums)<<endl;
    ss.Print(nums);
    return 0;
}