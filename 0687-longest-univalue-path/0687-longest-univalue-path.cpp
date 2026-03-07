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
    int ans;
    int dfs(TreeNode* root,int val){
        if(root==NULL)return 0;
        int left=dfs(root->left,root->val);
        int right =dfs(root->right,root->val);
        ans=max(ans,left+right);
        return root->val==val?max(left,right)+1:0;
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};