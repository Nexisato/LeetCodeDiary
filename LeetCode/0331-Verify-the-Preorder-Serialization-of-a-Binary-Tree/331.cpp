/*
LeetCode 331: Verify Preorder Serialization of a Binary Tree
@Description:
One way to serialize a binary tree is to use preorder traversal.
When we encounter a non-null node, we record the node's value.
If it is a null node, we record using a sentinel value such as '#'.

For example, the above binary tree can be serialized to the string
"9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node. Given a string of
comma-separated values preorder, return true if it is a correct preorder traversal
serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer
or a character '#' representing null pointer.

You may assume that the input format is always valid.
    For example, it could never contain two consecutive commas, such as "1,,3".

Constraints:
1 <= preorder.length <= 10^4
preoder consist of integers in the range [0, 100] and '#' separated by commas ','.
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：统计出入度/利用栈模拟
1. 根节点视为只有两个出度的节点，叶子节点所指向的空节点视为只有一个入度的节点
2. 二叉树视为有向图，一条有向边对整个图贡献一个入度和一个出度
3. 遍历到结尾前， inDeg <= outDeg，出度视为提供挂载点，入度视为消耗挂载点，
    - 只有根节点会额外提供出度，其他节点要么平衡出入度差，要么消耗出度
    - 因此要保证inDeg == outDeg，只有遍历到最终节点时，入度【刚好增加到】与出度平衡的值
*/
class Solution {
private:
	// C++中的split函数需要我们手动实现
	vector<string> split(const string& preorder) {
		stringstream ss(preorder);
		string c;
		vector<string> res;
		while (getline(ss, c, ','))
			res.push_back(c);
		return res;
	}

public:
	bool isValidSerialization(string preorder) {
		if (preorder == "#")
			return true;
		int inDeg = 0, outDeg = 0;
		vector<string> serial = split(preorder);
		int n = serial.size();
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				if (serial[i] == "#")
					return false;
				else {
					outDeg += 2;
					continue;
				}
			}
			if (serial[i] == "#") {
				inDeg += 1;
			} else {
				inDeg += 1;
				outDeg += 2;
			}
			if (i != n - 1 && inDeg >= outDeg)
				return false;
		}
		return inDeg == outDeg;
	}
};
/*
思路：利用栈先后判断左子树——右子树——根节点
1. 若一个节点为叶子节点，则其后的两个值均为'#'
2. 若一个节点非叶子节点，则
    - 两个孩子都是非'#'
    - 一个孩子是'#'，另一个孩子非'#'
3. 对于有效的节点，使用'#'替代，如'4##'替换为'#'，此时叶子节点变为空节点
*/
class Solution_stack {
public:
	bool isValidSerialization(string preorder) {
		if (preorder == "#")
			return true;
		vector<string> st;
		string c;
		stringstream ss(preorder);
		while (getline(ss, c, ',')) {
			st.emplace_back(c);
			while (st.size() >= 3 && st[st.size() - 1] == "#" &&
			       st[st.size() - 2] == "#" && st[st.size() - 3] != "#") {
				st.pop_back();
				st.pop_back();
				st.back() = "#";
			}
		}
		return (st.size() == 1) && (st.back() == "#");
	}
};
int main() { return 0; }