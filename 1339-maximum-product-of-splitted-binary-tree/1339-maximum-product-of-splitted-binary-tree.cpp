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
    long long cnt;
    long long ts;
    long long calsum(TreeNode* r){
        if(!r)return 0;
        return r->val+calsum(r->left)+calsum(r->right);
    }
    long long dfs(TreeNode* root){
        if(!root)return 0;
        long long ls=dfs(root->left);
        long long rs=dfs(root->right);
        long long css=root->val+ls+rs;
        long long rss=ts-css;
        long long cp=css*rss;
        cnt=max(cnt,cp);
        return css;
    }
    int maxProduct(TreeNode* root) {
         ts=calsum(root);
        cnt=0;
        dfs(root);
         return cnt % 1000000007;
    }
};