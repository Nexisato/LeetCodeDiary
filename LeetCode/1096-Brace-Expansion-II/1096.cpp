#include <bits/stdc++.h>
using namespace std;

/*
类比中缀表达式，我们需要用到两个栈
*/
class Solution {
private:
public:
	vector<string> braceExpansionII(string expression) {
		vector<char> op;
		vector<set<string>> st;

		//栈顶运算符用于计算
		auto ope = [&]() {
			int l = st.size() - 2, r = st.size() - 1;
			if (op.back() == '+') {
				st[l].merge(st[r]);
			} else {
				// catersian product, 对每个 set 中的字符串进行内积
				set<string> tmp;
				for (auto& left : st[l])
					for (auto& right : st[r])
						tmp.insert(left + right);
				st[l] = move(tmp);
				// move函数可以将 tmp 中的所有元素转移到 st[l]中，避免产生不必要的元素复制和内存开销，
				//减少资源的重复占用，tmp中的元素不再需要时，可以清空以释放内存空间
			}
			op.pop_back();
			st.pop_back();
		};
		//定义运算法则
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ',') {
				while (op.size() && op.back() == '*')
					ope();
				op.push_back('+');
			} else if (expression[i] == '{') {
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				op.push_back('{');
			} else if (expression[i] == '}') {
				while (op.size() && op.back() != '{')
					ope();
				op.pop_back();
			} else {
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				st.push_back({string(1, expression[i])});
			}
		}
		while (op.size())
			ope();
		return {st.back().begin(), st.back().end()};
	}
};
int main() {
	string expresssion = "{a,b}{c,{d,e}}";
	Solution ss;
	vector<string> res = ss.braceExpansionII(expresssion);
	for (auto a : res)
		cout << a << " ";
	cout << "\n";

	return 0;
}