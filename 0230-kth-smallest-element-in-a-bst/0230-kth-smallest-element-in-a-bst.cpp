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
    void BST(TreeNode* root,int &cnt,int &ans,int k){
        if(root==NULL)return;
        BST(root->left,cnt,ans,k);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return ;
        }
        BST(root->right,cnt,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int ans;
        BST(root,cnt,ans,k);
        return ans;
    }
};