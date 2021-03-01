
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    vector<int> tmp;
    //思路：分治，左右两个区间sorted之后，再对整体进行归并
    //时间复杂度:O(nlogn) 空间复杂度:O(n)
    void mergeSort(vector<int> &nums,int l,int r){
        if(l>=r) return;
        int mid=(l+r)>>1;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);

        int p1=l,p2=mid+1;
        int p=0;
        while(p1<=mid&&p2<=r)
            tmp[p++]=(nums[p1]<nums[p2])?nums[p1++]:nums[p2++];
        while(p1<=mid) tmp[p++]=nums[p1++];
        while(p2<=r) tmp[p++]=nums[p2++];

        for(int i=0;i<r-l+1;++i) nums[i+l]=tmp[i];
    }
public:
    vector<int> sortArray(vector<int> &nums){
        tmp.resize((int)nums.size(),0);
        mergeSort(nums,0,(int)nums.size()-1);
        return nums;
    }
};


int main(){
    vector<int> nums={9,7,8,4,5,2,0,9,6};
    Solution ss;
    ss.sortArray(nums);
    for(vector<int>::iterator it=nums.begin();it<nums.end();it++)
        cout<<*(it)<<" ";
    return 0;
}