#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	//暴力，会超时
	bool containsDuplicate_1(vector<int>& nums) {
		bool flag = false;
		;
		for (int i = 0; i < nums.size() - 1; i++)
			for (int j = i; j < nums.size(); j++)
				if (nums[i] == nums[j]) {
					flag = true;
					break;
				}
		return flag;
	}
	bool containsDuplicate_2(vector<int>& nums) {
		return nums.size() > set<int>(nums.begin(), nums.end()).size();
	}
	/*bool containsDuplicate(vector<int>& nums){

	}*/
	void Print(vector<int>& nums) {
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it += 1) {
			cout << *(it) << endl;
		}
	}
};
int main() {
	// Solution ss;
	// vector<int> nums={0,0,1,1,1,2,2,3,3,4};
	// cout<<ss.containsDuplicate(nums)<<endl;
	map<int, string> mapStudent;

	//第一种：用insert插入函数pair
	mapStudent.insert(pair<int, string>(0, "Student_0"));

	//第二种：用insert插入value_type数据
	mapStudent.insert(map<int, string>::value_type(1, "Student_1"));

	//第三种：用array方式插入
	mapStudent[123] = "Student_first";
	mapStudent[456] = "Student_second";

	// insert是否可以覆盖关键字所在位置的值
	pair<map<int, string>::iterator, bool> Insert_pair;
	Insert_pair =
	    mapStudent.insert(map<int, string>::value_type(1, "Student_one_changed_flag"));

	/*if(!Insert_pair.second)
	    cout<<"Inserting Failed"<<endl;*/
	string tmp = "Student_1";
	map<int, string>::iterator iter = mapStudent.find(123);
	if (iter != mapStudent.end())
		cout << "Value: " << iter->second << endl;

	return 0;
}