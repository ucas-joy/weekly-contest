#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int>res;
		if (nums.size() == 0) return res;
		int n = nums.size();
		int i = 0;
		while (i < n) {
			if (nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
			else {
				i++;
			}
		}
		for (i = 0; i < n; ++i) {
			if (nums[i] != i + 1)
			{
				res.push_back(nums[i]);
				res.push_back(i + 1);
			}
		}

		return res;
	}
	
};
int main645()
{
	//vector<int>a{ 3,2,3,4,6,5 };
	vector<int>a{3, 2,2 };
	Solution s;
	vector<int>res = s.findErrorNums(a);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}