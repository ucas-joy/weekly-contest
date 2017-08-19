
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<numeric>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		if (root == NULL) return res;
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			vector<int>tmp;
			int size = q.size();
			for (int i = 0; i < size; ++i)
			{
				TreeNode *tmp_node = q.front();
				q.pop();
				tmp.push_back(tmp_node->val);
				if (tmp_node->left) q.push(tmp_node->left);
				if (tmp_node->right)q.push(tmp_node->right);
			}
			double sum = 0;
			sum = accumulate(tmp.begin(), tmp.end(), sum);
			res.push_back(sum / size);
		}
		return res;
	}
};