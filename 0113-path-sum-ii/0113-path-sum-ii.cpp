/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>>ans;
public:
    void helper(TreeNode* root,int targetsum,vector<int>l,int sum){
        if(root==nullptr) return ;
        sum+=root->val;
        l.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
          if(targetsum==sum) ans.push_back(l);
        }
        helper(root->left,targetsum,l,sum);
        helper(root->right,targetsum,l,sum);
        l.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>l;
        helper(root,targetSum,l,0);
        return ans;
    }
};