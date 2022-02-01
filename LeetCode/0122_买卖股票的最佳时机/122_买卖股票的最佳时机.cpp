#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        for(int i=1;i<prices.size();i++)
            result+=max(0,prices[i]-prices[i-1]);
        
        return result;
    }
};

int main(){
    vector<int> prices={7,1,5,3,6,4}; 
    Solution ss;
    cout<<ss.maxProfit(prices);
    /*for(vector<int>::iterator it=prices.begin();it<prices.end();it++)
        cout<<*(it)<<endl;*/
    return 0;
}