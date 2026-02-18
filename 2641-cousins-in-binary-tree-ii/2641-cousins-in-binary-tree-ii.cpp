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
int levelsum[100000];
    void calculatesum(TreeNode* root,int level){
        if(root==NULL) return ;
        levelsum[level]+=root->val;
        calculatesum(root->left,level+1);
        calculatesum(root->right,level+1);
    }
    void replace(TreeNode* root, int siblingsum,int level){
        if(root==NULL)return;
        int left=root->left!=NULL?root->left->val:0;
        int right=root->right!=NULL?root->right->val:0;
        if(level==0||level==1)root->val=0;
        else root->val=levelsum[level]-root->val-siblingsum;
        replace(root->left,right,level+1);
        replace(root->right,left,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        calculatesum(root,0);
        replace(root,0,0);
        return root;
    }
};