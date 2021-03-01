/*
《程序员的算法趣题》 A Q18 水果酥饼日
Description:
日本每月的 22 日是水果酥饼日。因为看日历的时候，22 日的上方刚好是 15 日，也就是“‘22’ 这个数字上面点缀着草莓”[1]

切分酥饼的时候，要求切分后每一块上面的草莓个数都不相同。
假设切分出来的 N 块酥饼上要各有“1~N 个（共 N(N + 1)÷2 个草莓）”。

但这里要追加一个条件，那就是“一定要使相邻的两块酥饼上的数字之和是平方数”。
举个例子，假设 N ＝ 4 时采用如 [1 3 2 4]的切法。这时，虽然 1 + 3 ＝ 4 得到的是平方数，
但“1 和 4” “2 和 3” “2 和 4”的部分都不满足条件

notes:如果将日语的 15 拆为 1 和 5 发音，则与日语“草莓”一词发音相同，而水果酥饼中最为著名的就是草莓酥饼。
同时，日历中 15 总在 22 的上面，故有此说法。 ——译者注。
*/
#include<bits/stdc++.h>
using namespace std;
/*
思路：Hamiltonian Cycle + DFS
问题实质：找到最小的正整数n，使得存在某个[1..n]的循环排列，任意相邻两项的和为完全平方数
1. 将n个数看作无向图中的n个节点，若两个节点 n1 n2之和为完全平方数，则对应节点之间存在一条无向边
2. 问题转化为：从某一个节点开始，通过无向边遍历每个节点恰好一次，并最终返回初始节点（即哈密顿回路,NP Problem）
3. 由于数组是循环的，依次可以假定数组的首位为1
4. 利用DFS(回溯)方法找出答案{
        若上一步我们位于x对应的节点，则当前步移动至与节点x相连且未被走过的节点；
        若不存在这样的节点，则进行回溯；
        否则，枚举每一个满足要求的节点并递归地搜索；
    }
5. 由于我们需要找到最小的n，因此将DFS包装成含有形参n的函数，并从小到大枚举n进行搜索
*/
class Solution {
private:
    const int MAX_N = 999;
    //记录无向图
    vector<vector<int>> edges;
    //记录搜索过程中每个数是否被使用过
    vector<bool> flags;
    //记录搜索过程中找到的序列
    vector<int> ans;
    //是否找到答案
    bool isFound = false;
private:
    void dfs(int pos, int n) {
        if (pos == n) {
            //判断序列首尾之和是否为完全平方数
            int sum = ans[0] + ans.back();
            int root = sqrt(sum);
            if (root * root == sum) isFound = true;
        }else if (pos == 0) {   //循环数组，可以指定第一个数为1
            flags[1] = true;
            ans.push_back(1);
            dfs(pos + 1, n);
            if (isFound) return;
            flags[1] = false;   //搜索失败，原条件复位回溯
            ans.pop_back();
        }else{
            //选择 与上一个位置的数可形成完全平方数 且 未被选择 的数
            for (int num : edges[ans.back()]) {
                if (!flags[num]) {
                    flags[num] = true;
                    ans.push_back(num);
                    dfs(pos + 1, n);
                    if (isFound) return;
                    flags[num] = false;
                    ans.pop_back();
                }
            }
        }
    }
public:
    int MAX_NUM(vector<int> arr){
        int max = arr[0];
        for(int num : arr){
            if (num > max) 
                max = num;
        }
        return max;
    }
    vector<int> minimalFruitPie() {
        //枚举n
        for (int n = 2; n < MAX_N; ++n) {
            edges.assign(n+1, vector<int>{});
            //建立无向图
            for (int i = 1; i <= n; ++i){
                //枚举平方数
                for (int root = 1; root * root <= i + n; ++root) {//平方数最大不超过 n + (n-1)
                    int j = root * root - i;
                    if (j > i) {
                        edges[i].push_back(j);
                        edges[j].push_back(i);
                    }
                }
            }
            flags.assign(n + 1, 0);
            dfs(0, n);
            if (isFound)
                return ans;
        }
    }
};

int main() {
    Solution ss;
    vector<int> res = ss.minimalFruitPie();
    cout << "n: " << ss.MAX_NUM(res) << endl;
    cout << "[ ";
    for (vector<int>::iterator it = res.begin(); it != res.end(); it++)
        cout << *(it) << " ";
    cout << "]" << endl;
    cout << "[ ";
    for (int i = 0; i < res.size() - 1; i++)
        cout << res[i] + res[i + 1] << " ";
    cout << "]" << endl;
    return 0;
}