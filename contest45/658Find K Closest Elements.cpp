#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<pair<int, int>>pos;
		for (int i = 0; i < arr.size(); ++i)
		{
			pos.push_back(make_pair(abs(x - arr[i]), arr[i]));
		}
		sort(pos.begin(), pos.end(), cmp);
		vector<int>res;
		int count = 0;
		for (int i = 0; i < pos.size(); ++i)
		{
			res.push_back(pos[i].second);
			count++;
			if (count == k)
				break;
		}
		sort(res.begin(), res.end());
		return res;
	}
	static bool cmp(pair<int, int>a, pair<int, int >b) {
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	}
};
int main658()
{
	vector<int>a{ 1,2,3,4,5 };
	Solution s;
	vector<int>cnt = s.findClosestElements(a, 4, 3);
	for (int i = 0; i < cnt.size(); ++i)
	{
		cout << cnt[i] << endl;
	}
	return 0;
}