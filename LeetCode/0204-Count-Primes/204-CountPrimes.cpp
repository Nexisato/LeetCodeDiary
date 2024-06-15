/*
LeetCode: 204 Count Primes
Description:
Count the number of prime numbers less than a non-negative number, n.

Constraints:
0 <= n <= 5 * 10^6
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool isPrime(int num) {
		if (num <= 1)
			return false;
		if (num == 2 || num == 3)
			return true;
		int bound = int(sqrt(num));
		for (int i = 2; i <= bound; i++)
			if (num % i == 0)
				return false;
		return true;
	}

public:
	int countPrimes(int n) {
		if (n <= 1)
			return 0;
		int count = 0;
		for (int num = 2; num <= n - 1; num++)
			if (isPrime(num))
				count += 1;
		return count;
	}
	int countPrimes_Eratosthenes(int n) {
		vector<bool> isPrime(n, true);
		int res = 0;
		for (int num = 2; num < n; ++num) {
			if (isPrime[num]) {
				res += 1;
				if ((long long)num * num < n)
					for (int j = num * num; j < n; j += num)
						isPrime[j] = false;
			}
		}
		return res;
	}
	int countPrimes_linear(int n) {
		vector<int> primes;
		vector<bool> isPrime(n, true);
		for (int num = 2; num < n; ++num) {
			if (isPrime[num])
				primes.push_back(num);
			for (int i = 0; i < primes.size() && num * primes[i] < n; ++i) {
				isPrime[num * primes[i]] = false;
				if (num % primes[i] == 0)
					break;
			}
		}
		return primes.size();
	}
};

int main() {
	int n = 9;
	Solution ss;
	cout << ss.countPrimes_Eratosthenes(n) << endl;
	return 0;
}