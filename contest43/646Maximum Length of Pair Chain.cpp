#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(const vector<int>&a, const vector<int>&b)
	{
		return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
	}
	int findLongestChain(vector<vector<int>>& pairs) {
		int size = pairs.size();
		if (size == 0)return 0;
		sort(pairs.begin(), pairs.end(), cmp);
		vector<int>dp(size + 1, 0);
		int maxlen = 0;
		dp[0] = 1;
	
		for (int i = 1; i < size; ++i){
				int m = 0;
				for (int j = i; j >= 0; --j){
					if (pairs[i][0] > pairs[j][1]){
						m = max(m, dp[j]);
					}
				}
				dp[i] = m + 1;
				maxlen = max(dp[i], maxlen);
			}
		return maxlen;
	}
};
int main646()
{
	vector<vector<int>>a{ {1,2} ,{14,15},{3,10},{9,11},{6,7},{4,5},{12,13},{8,20}};
	//vector<vector<int>>a{ {1,2},{2,3},{3,4} };
	Solution s;
	int c = s.findLongestChain(a);
	cout << c << endl;
	return 0;
}