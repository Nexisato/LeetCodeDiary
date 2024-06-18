#include <algorithm>
#include <gtest/gtest.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
	string discountPrices(string sentence, int discount) {
		stringstream sin(sentence), sout;
		sout << fixed << setprecision(2);

		string word;
		while (sin >> word) {
			if (word[0] == '$' && word.size() > 1 && all_of(word.begin() + 1, word.end(), ::isdigit)) {
				double price = stoll(word.substr(1, word.size() - 1)) * (1.0 - discount / 100.0);
				sout << "$" << price;
			} else {
				sout << word;
			}
			sout << " ";
		}
		string res = sout.str();
		res.pop_back();

		return res;
	}
};

TEST(Solution, repeated_string_match) {
	Solution solution;

	string sentence1 = "$2$3 $10 $100 $1 200 $33 33$ $$ $99 $99999 $9999999999";
	string expected = "$2$3 $9.50 $95.00 $0.95 200 $31.35 33$ $$ $94.05 $94999.05 "
	                  "$9499999999.05";
	EXPECT_EQ(solution.discountPrices(sentence1, 5), expected);
}

TEST(Solution, max_digits) {
	Solution solution;

	string sentence1 = "706hzu76jjh7yufr5x9ot60v149k5 $7651913186 pw2o $6";
	string expected = "706hzu76jjh7yufr5x9ot60v149k5 $5509377493.92 pw2o $4.32";
	EXPECT_EQ(solution.discountPrices(sentence1, 28), expected);
}

// g++ -o test 2288.cpp -lgtest
int main() {
	testing::InitGoogleTest();

	return RUN_ALL_TESTS();
}