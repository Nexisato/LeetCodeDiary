#include <bits/stdc++.h>
using namespace std;

class MonotoninStack {
    stack<int> st;
    vector<int> nums;
    for (int i = 0; i < nums.size(); i++) {
	    while(!st.empty() && st.top() > nums[i]) {
		    st.pop();
	    }
	st.push(nums[i]);
    }
};

