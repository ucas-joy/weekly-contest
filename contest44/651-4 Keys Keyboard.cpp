#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxA(int N) {
		vector<int>dp(N + 1, 0);
		for (int i = 0; i < N + 1; ++i) {
			dp[i] = i;
		}
		int m = 0;
		for (int i = 7; i <= N; ++i)
		{
			for (int j = i-1; j >= 2; --j)
			{
				m = max(m, j*dp[i - j - 1]);
			}
			dp[i] = m;
		}
		return dp[N];
	}
};
int main6514()
{
	int x = 7;
	Solution s;
	int cnt = s.maxA(x);
	cout << cnt << endl;
	return 0;
}