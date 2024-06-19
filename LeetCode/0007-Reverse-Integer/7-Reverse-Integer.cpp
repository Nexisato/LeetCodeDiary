/*
Description:
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment
that could only store integers within the 32-bit signed integer range: [−2^31,  2^31 −
1]. For the purpose of this problem, assume that your function returns 0 when the
reversed integer overflows.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	//思路：注意判断溢出
	int reverse(int x) {
		/*int bit=0;
		for(int i=x;i!=0;i=i/10)bit++;
		int result=0;
		for(int i=0;i<bit;i++){
		    result+=x%10;
		    x/=10;
		    if(i!=bit-1)
		         result*=10;
		}
		return result;*/
		long result = 0;
		while (x) {
			result = result * 10 + x % 10;
			x /= 10;
		}
		if (result > INT32_MAX || result < INT32_MIN)
			result = 0;
		return result;
	}
};

int main() {
	long tmp = 964632435 * 10;
	Solution ss;
	cout << ss.reverse(tmp);

	return 0;
}