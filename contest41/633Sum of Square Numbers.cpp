#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool judgeSquareSum(int c) {
		bool found = false;
		for (long int i = 0; i <= c; ++i)
		{
			int t = sqrt(c - i*i);
			if ((i*i) + t*t == c)
			{
				found = true;
				break;
			}
		}
		return found;
	}
};
int main633()
{
	int a = 3;
	Solution s;
	bool is = s.judgeSquareSum(a);
	cout << is << endl;
	return 0;
}