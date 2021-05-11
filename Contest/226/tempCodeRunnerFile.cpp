        vector<bool> res;
        int N = candiesCount.size();
        vector<long long> Sum(N + 1);
        for (int i = 1; i <= N ; ++i)
            Sum[i] = Sum[i - 1] + candiesCount[i - 1]; //Sum[i]表示Typei以前的所有糖果总和
        for (vector<int>& query : queries) {
            bool flag = true;
            int favType = query[0], favDay = query[1], dailyCap = query[2];
            long long minSum = favDay;
            long long maxSum = (long long)dailyCap * (favDay + 1);

            if (maxSum <= Sum[favType] || minSum >= Sum[favType + 1])
                flag = false;
            /*
            for(int i = 0; i < N; i++) {
                minSum -= candiesCount[i];
                maxSum -= candiesCount[i];
                if (minSum > 0)
                    minType++;
                if (maxSum > 0)
                    maxType++;
                if (minSum <= 0 && maxSum <= 0)
                    break;
            }
            if (minType > favType || maxType < favType)
                flag = false;
            */
            res.push_back(flag);
        }
        return res;