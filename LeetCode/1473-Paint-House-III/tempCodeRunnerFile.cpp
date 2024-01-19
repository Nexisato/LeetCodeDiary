        int dp[m][target + 1][n + 1];
        memset(dp, 0x3f3f3f3f, sizeof(dp));

        //初始化
        if (houses[0] == 0) {
            for (int k = 1; k <= n; ++k)
                dp[0][1][k] = cost[0][k - 1];
        }
        else
            dp[0][1][houses[0]] = 0;

        //状态转移
        for (int i = 1; i < m; ++i) {
            //当前房子无颜色
            if (houses[i] == 0) {
                for (int cur_color = 1; cur_color <= n; ++cur_color)
                    for (int prev_color = 1; prev_color <= n; ++prev_color)
                        for (int j = 1; j <= target; ++j) {
                            if (cur_color == prev_color)
                                dp[i][j][cur_color] = min(dp[i][j][cur_color], 
                                                    cost[i][cur_color - 1] + dp[i - 1][j][cur_color]);
                            else
                                dp[i][j][cur_color] = min(dp[i][j][cur_color],
                                                    cost[i][cur_color - 1] + dp[i - 1][j - 1][prev_color]);
                        }
            }
            //当前房子有颜色
            else {
                int cur_color = houses[i];
                for (int prev_color = 1; prev_color <= n; ++prev_color)
                    for (int j = 1; j <= target; ++j) {
                        if (cur_color == prev_color)
                            dp[i][j][cur_color] = min(dp[i][j][cur_color], 
                                                    dp[i - 1][j][cur_color]);
                        else
                            dp[i][j][cur_color] = min(dp[i][j][cur_color],
                                                    dp[i - 1][j - 1][prev_color]);
                    }
            }
        }
        
        int res = *min_element(dp[m - 1][target], dp[m - 1][target] + n + 1);
        return (res == 0x3f3f3f3f) ? -1 : res;