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
TreeNode* ans;
int maxi=0;
    int dfs(TreeNode* root,int depth){
        maxi=max(maxi,depth);
        if(root==NULL) return depth;
        int l=dfs(root->left,depth+1);
        int r=dfs(root->right,depth+1);
        if(l==maxi&&r==maxi) ans=root;
        return max(l,r);

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};