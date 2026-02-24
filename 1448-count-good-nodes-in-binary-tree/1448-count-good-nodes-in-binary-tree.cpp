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
int cnt=0;
    void dfs(TreeNode* root,int prev){
        if(root==NULL ) return;
        if(root->val>=prev) cnt++;
        prev=max(prev,root->val);
        dfs(root->left,prev);
        dfs(root->right,prev);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return cnt;
    }
};