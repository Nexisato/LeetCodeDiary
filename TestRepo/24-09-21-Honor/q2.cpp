#include <functional>
#include <iostream>
using namespace std;

int main() {
    // 无魔法：17m/s
    // 有魔法：60 m / s, 消耗十点
    // 站着不动：4点 / s
    // 初始魔法值，安全距离，火山爆发时间
    int M, D, T;
    cin >> M >> D >> T;
    bool res_flag = false;
    int res_delta = 0;
    int res_time = INT32_MAX;

    function<void(int, int, int)> dfs = [&](int cur_t, int cur_magic,
                                            int cur_d) -> void {
        if (cur_t <= T && cur_d >= D) {
            res_time = min(res_time, cur_t);
        }
        if (cur_t >= T) {
           res_delta = max(res_delta, cur_d);
           return;
        }
        int max_d = cur_d;
        dfs(cur_t + 1, cur_magic, cur_d + 17);
        if (cur_magic >= 10) {
             dfs(cur_t + 1, cur_magic - 10, cur_d + 60);
        }
        dfs(cur_t + 1, cur_magic + 4, cur_d);

    };
    dfs(0, M, 0);
    if (res_delta >= D) {
        res_flag = true;
    } else {
        res_flag = false;
    }

    if (res_flag) {
        cout << "YES " << res_time << endl;
    } else {
        cout << "NO " << res_delta << endl;
    }

    return 0;
}