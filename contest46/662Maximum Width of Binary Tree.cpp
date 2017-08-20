#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 typedef long long ll;
 class Solution {
 public:
	 int widthOfBinaryTree(TreeNode* root) {
		 ll ans = 0;
		 root->val = 0;
		 queue<TreeNode*> q;
		 q.push(root);
		 for (; !q.empty();)
		 {
			 int sz = q.size();
			 ll mini = 1e18, maxi = -1e18;
			 for (int i = 0; i < sz; ++i)
			 {
				 auto cur = q.front();
				 q.pop();
				 maxi = max(maxi, (ll)cur->val);
				 mini = min(mini, (ll)cur->val);
				 if (cur->left != NULL)
				 {
					 cur->left->val = 2 * (cur->val);
					 q.push(cur->left);
				 }
				 if (cur->right != NULL)
				 {
					 cur->right->val = 2 * (cur->val) + 1;
					 q.push(cur->right);
				 }
			 }
			 ans = max(ans, maxi - mini + 1);
		 }


		 return (int)ans;
	 }
 };