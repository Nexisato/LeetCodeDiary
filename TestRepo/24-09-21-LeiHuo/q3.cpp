#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct gift_t {
    int id;
    int t;  // 0 代表需要消耗 a 的中级天赋材料, 1 代表消耗 a 的高级天赋材料
    int a;
    int b;  // 激活该节点增加的能力值

    gift_t(int _id, int ti, int ai, int bi) : id(_id), t(ti), a(ai), b(bi) {}
};

int main() {
    // 天赋节点数
    int n;
    cin >> n;
    // 每个中级天赋消耗的钻石 和 每个高级天赋消耗的钻石
    int X, Y;
    cin >> X >> Y;
    // 初始拥有的钻石数量 和 高级天赋自选包的数量
    int A, B;
    cin >> A >> B;
    vector<vector<int>> edges(n + 1, vector<int>());
    vector<int> indegs(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        int prev;
        cin >> prev;
        edges[prev].push_back(i);
        ++indegs[i];
    }
    vector<int> init_nodes;
    for (int i = 1; i <= n; ++i)
        if (indegs[i] == 0)
            init_nodes.push_back(i);
    vector<gift_t> gifts;
    gifts.push_back(gift_t(0, 0, 0, 0));
    for (int i = 1; i <= n; ++i) {
        int ti, ai, bi;
        cin >> ti >> ai >> bi;
        gifts.push_back(gift_t(i, ti, ai, bi));
    }

    int res = 0;

    // idx, 当前钻，当前材料包，当前能力值
    function<void(int, int, int, int)> dfs = [&](int idx, int cur_A, int cur_B, int cur_res) {
        gift_t cur_gift = gifts[idx];
        if (cur_gift.t == 0) {
            if (cur_A < cur_gift.a * X) {
                res = max(res, cur_res);
                return;
            }
            cur_A -= X * cur_gift.a;
            cur_res += cur_gift.b;
            if (edges[idx].size() == 0) {
                res = max(res, cur_res);
                return;
            }
            
            for (auto&& next : edges[idx])
                dfs(next, cur_A, cur_B, cur_res);
        
        }
        else if (cur_gift.t == 1) {
            int A_consume = cur_gift.a * Y;
            int B_consume = cur_gift.a;
            if (cur_A < A_consume && cur_B < B_consume) {
                res = max(res, cur_res);
                return;
            }
            if (cur_A >= A_consume) {
                int tmp_A = cur_A - A_consume;
                int tmp_res = cur_res + cur_gift.b;
                if (edges[idx].size() == 0) {
                    res = max(res, tmp_res);
                    return;
                }
                for (auto&& next : edges[idx])
                    dfs(next, tmp_A, cur_B, tmp_res);
            

            }
            if (cur_B >= B_consume) {
                int tmp_B = cur_B -  B_consume;
                int tmp_res = cur_res + cur_gift.b;
                if (edges[idx].size() == 0) {
                    res = max(res, tmp_res);
                    return;
                }
                for (auto&& next : edges[idx])
                    dfs(next, cur_A, tmp_B, tmp_res);
            }
        }

    };
    for (auto&& node : init_nodes)
        dfs(node, A, B, 0);


    std::cout << res << endl;


    return 0;
}