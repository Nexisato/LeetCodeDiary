#include <bits/stdc++.h>
using namespace std;
/**
 * @brief
 * 转换成 bit manipulation
 * dp 数组记录的是全部状态，不要依照给定数组逐状态去思考
 *
 */
class Solution {
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
		int n = people.size();
		vector<int> res;

		unordered_map<string, int> table;
		int numSkill = req_skills.size();
		for (int i = 0; i < numSkill; ++i)
			table[req_skills[i]] = i;

		vector<int> personBit(n, 0);
		for (int i = 0; i < n; ++i) {
			vector<string> person = people[i];
			for (const auto& skill : person)
				personBit[i] |= (1 << table[skill]);
		}
		vector<int> dp(1 << numSkill, n); // dp[i] represents the least number of persons to construct status i (binary)
		vector<int> prev_skill(1 << numSkill, 0), prev_people(1 << numSkill, 0);
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int prev = 0; prev < (1 << numSkill); ++prev) {
				int comb = prev | personBit[i];
				if (dp[comb] > dp[prev] + 1) {
					dp[comb] = dp[prev] + 1;
					prev_skill[comb] = prev;
					prev_people[comb] = i;
				}
			}
		}
		int totalBit = (1 << numSkill) - 1;
		while (totalBit > 0) {
			res.push_back(prev_people[totalBit]);
			totalBit = prev_skill[totalBit];
		}
		return res;
	}
};

int main() { return 0; }