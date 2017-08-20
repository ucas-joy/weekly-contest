#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>>res;
		int row = M.size();
		int col = M[0].size();
		for (int i = 0; i < row; ++i) {
			vector<int>tmp;
			for (int j = 0; j < col; ++j) {
				int count = 1;
				int sum = M[i][j];
				if (i - 1 >= 0) {
					sum += M[i - 1][j];
					count++;
				}
				if (j - 1 >= 0) {
					sum += M[i][j - 1];
					count++;
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					sum += M[i - 1][j - 1];
					count++;
				}
				if (i + 1 < row) {
					sum += M[i + 1][j];
					count++;
				}
				if (j + 1 < col) {
					sum += M[i][j + 1];
					count++;
				}
				if (i + 1 < row && j + 1 < col) {
					sum += M[i + 1][j + 1];
					count++;
				}
				if (i - 1 >= 0 && j + 1 < col) {
					sum += M[i - 1][j + 1];
					++count;
				}
				if (i + 1 < row && j - 1 >= 0) {
					sum += M[i + 1][j - 1];
					++count;
				}
				sum = sum / count;
				tmp.push_back(sum);
			}
			res.push_back(tmp);
		}
		return res;
	}
};
int main661()
{
	vector<vector<int>>a{
		{2,3,4},
		{5,6,7},
		{8,9,10},
		{11,12,13},
		{14,15,16}
	};
	Solution s;
	vector<vector<int>>res = s.imageSmoother(a);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[0].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}