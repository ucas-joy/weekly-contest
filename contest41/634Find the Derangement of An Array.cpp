#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class Solution
{
public:
	int findDerangement(int n) {
		vector<long long int>dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 0;
		dp[2] = 1;
		for (int i = 3; i <= n; ++i)
		{
			dp[i] = (i - 1)*(dp[i - 1] + dp[i - 2]);
			dp[i] = dp[i] % 1000000007;
		}
		return dp[n] % 1000000007;
	}
};
int main634()
{
	int t = 13;
	Solution s;
	int n = s.findDerangement(t);
	cout << n << endl;
	return 0;
}