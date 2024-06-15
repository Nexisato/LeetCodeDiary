/**
 * @file redbook_3.cpp
 * @Question: 小红的攻略
 * @Description:
小红是小红书的一个博主，她有很多的粉丝，有一些粉丝想让小红出一篇上尾市的旅游攻略。
上尾市有n个景点，有 m条路线，每个景点的攻略价值是 a，要花费h时间浏览，不同景点之间的交通时间为 w。
小红最多会选择3个相邻的景点，然后按顺序将景点写进攻略，
她需要保证每个景点的浏览时间加上景点之间的交通时间总和不超过k，并且使得攻略的价值尽可能大，即是点的总价值尽可能大。
求小红的攻略的最大价值。

输入描述：
第一行输入三个整数 n,m(1<=n,m <=10^5),k(1 <=k<= 10^9)
第二行输入n 个整数表示数组 a(1 <=a:i<=10^9)。
第三行输入n个整数表示数组 h(1<=h<=10^9)
接下来m行，每行输入三个整数 u,v(1<=u,v <=n),w(1<= w<=10^9) 表示景点u,v 之间的交通时间为 w。

输出描述
一个整数，小红的攻略的最大价值。
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * @brief:
 * a 为攻略价值, h 为浏览时间
 * 【注意】 最多选择 3 个相邻的城市，不一定非要选择全3个
 * max a1 + a2 + a3
 * s.t. h1 + h2 + h3 + w12 + w23 <= k
 *
 */
struct Node {
	int value, time;
	Node(int v, int t) : value(v), time(t) {}
};

int main() {
	const int INF = 0x3f3f3f3f;
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), h(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	vector<vector<int> > cost(n, vector<int>(n, INF));
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		cost[u - 1][v - 1] = w;
		cost[v - 1][u - 1] = w;
	}

	// dp[i][j]前 i 个城市选择 j 个的最大价值，并记录时间
	vector<vector<Node> > dp(n + 1, vector<Node>(4, {0, 0}));
	for (int i = 0; i < n; ++i) {
		dp[i][0].value = 0;
		dp[i][0].time = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 3; ++j) {
			for (int neighbor_i = 0; neighbor_i < n; ++neighbor_i) {
				if (cost[i - 1][neighbor_i] != INF) {
					int value = a[neighbor_i];
					int time = cost[i - 1][neighbor_i];
				}
			}
		}
	}

	return 0;
}