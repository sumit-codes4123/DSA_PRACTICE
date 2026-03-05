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
    long long sums[100000] = {0};
    int maxLevel = 0;
    void dfs(TreeNode* root,int level){ 
        if(root==nullptr)return;
        sums[level]+=root->val;
        maxLevel=max(maxLevel,level);
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root,0);
        sort(sums,sums+maxLevel+1,greater<long long>());
        return (k > maxLevel + 1) ? -1 : sums[k - 1];
    }
};