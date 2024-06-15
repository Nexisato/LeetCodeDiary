#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	ostringstream ostr;
	// ostr.str("abc");
	//如果构造的时候设置了字符串参数,那么增长操作的时候不会从结尾开始增加,而是修改原有数据,超出的部分增长
	ostr << "[]";
	string data = ostr.str();
	data.erase(0, data.find_first_not_of("["));
	data.erase(data.find("]"));
	// cout << data << endl;
	cout << data.size() << endl;
	system("pause");
}