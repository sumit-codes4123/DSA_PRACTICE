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
public:
    int dfs(TreeNode* root,int mini ,int maxi){
        if(root==NULL) return maxi-mini;
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        return max(dfs(root->left,mini,maxi),
        dfs(root->right,mini,maxi));
       // return max-min;
    }
    int maxAncestorDiff(TreeNode* root) {
      return dfs(root,root->val,root->val);
    }
};