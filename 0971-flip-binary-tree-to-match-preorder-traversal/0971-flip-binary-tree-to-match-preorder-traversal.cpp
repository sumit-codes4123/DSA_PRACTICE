/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int i = 0;
    vector<int> ans;
    bool dfs(TreeNode* root, vector<int>&voyage) {
        if (!root) return true;
        if(root->val!=voyage[i++]) return false;
        if(root->left!=NULL&&root->left->val!=voyage[i]){
            ans.push_back(root->val);
            return dfs(root->right,voyage)&&dfs(root->left,voyage);
        }
        return dfs(root->left,voyage)&&dfs(root->right,voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ans.clear();
        if(dfs(root, voyage))
           return ans;
        return {-1};
    }
};