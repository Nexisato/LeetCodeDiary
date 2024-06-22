
#include <string>
#include <gtest/gtest.h>
using namespace std;


// 思路：视为 k 进制数，
// 从最高位开始，找到第一个比前一位大的数，然后将这个数减一，后面的数全部置为 a
class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        k += 'a';
        int n = s.length();
        int i = n - 1;
        ++s[i];
        while (i < n) {
            if (s[i] == k) {
                if (i == 0)
                    return "";
                s[i] = 'a';
                ++s[--i];
            } else if (i && (s[i] == s[i - 1] || i > 1 && s[i] == s[i - 2])) {
                ++s[i];
            } else {
                ++i;
            }
        }
        
        return s;
    }
};

TEST(smallestBeautifulString, case1) {
    string s = "abcz";
    int k = 26;
    Solution *ss = new Solution();
    string res = ss->smallestBeautifulString(s, k);
    EXPECT_EQ(res, "abda");
}

TEST(smallestBeautifulString, case2) {
    string s = "dc";
    int k = 4;
    Solution *ss = new Solution();
    string res = ss->smallestBeautifulString(s, k);
    EXPECT_EQ(res, "");
}


TEST(smallestBeautifulString, case3) {
    string s = "cegaf";
    int k = 7;
    Solution *ss = new Solution();
    string res = ss->smallestBeautifulString(s, k);
    EXPECT_EQ(res, "cegba");
}


int main() {
    testing::InitGoogleTest();


    return RUN_ALL_TESTS();
}