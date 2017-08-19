#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool isprime(int n) {
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) return false;
		}
		return true;
	}
	int Minexp(int n) {
		int i;
		for (i = 2; i * i <= n; ++i) {
			if (n % i == 0) break;
		}
		return n / i;
	}
	int minSteps(int n) {
		vector<int>dp(n + 1, 0);
		if (n == 0) return 0;
		else if (n == 1) return 0;
		else if (n == 2) return 2;
		dp[0] = 0;
		dp[1] = 0;
		dp[2] = 2;
		for (int i = 2; i <= n; ++i) {
			if (isprime(i)) {
				dp[i] = i;
			}
			else {
				int t = Minexp(i);
				dp[i] = dp[t] + i / t;
			}
		}
		return dp[n];
	}
};
int main6502()
{
	int n =9;
	cout << "n = " << n << endl;
	Solution s;
	int cnt = s.minSteps(n);
	cout << cnt << endl;
	return 0;
}