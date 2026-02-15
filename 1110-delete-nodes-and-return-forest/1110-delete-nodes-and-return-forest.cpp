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
        unordered_set<int>s;
        vector<TreeNode*>ans;
        TreeNode* dfs(TreeNode* root){
            if(root==NULL) return NULL;
            root->left=dfs(root->left);
            root->right=dfs(root->right);
            if(s.find(root->val)!=s.end()){
                if(root->left!=NULL) ans.push_back(root->left);
                if(root->right!=NULL) ans.push_back(root->right);
                delete root;
                return NULL;
            }
            return root;
        }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x:to_delete) s.insert(x);
        root= dfs(root);
        if(root) ans.push_back(root);
        return ans;
    }
};