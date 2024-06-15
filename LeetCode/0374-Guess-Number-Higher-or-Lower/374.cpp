/*
LeetCode 374: Guess Number Higher or Lower
@Desciription:
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns 3 possible results:
 -1: The number I picked is lower than your guess (i.e. pick < num).
 1: The number I picked is higher than your guess (i.e. pick > num).
 0: The number I picked is equal to your guess (i.e. pick == num).
Return the number that I picked.

Constraints:
1 <= n <= 2^31 - 1
1 <= pick <= n
*/
#include <bits/stdc++.h>
using namespace std;
/*
思路：二分
注意别越界
*/
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
	int guessNumber(int n) {
		int mid = -1;
		int l = 1, r = n;
		while (l < r) {
			mid = l + (r - l) / 2;
			if (guess(mid) == 0)
				return mid;
			else if (guess(mid) < 0)
				r = mid - 1;
			else
				l = mid + 1;
		}
		return l;
	}
};
int main() { return 0; }