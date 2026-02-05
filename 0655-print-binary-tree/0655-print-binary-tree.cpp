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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void dfs(TreeNode* root,vector<vector<string>>&ans,int row,int l,int r){
        if(root==NULL||ans.size()==row) return;
        int mid=(l+r)/2;
        ans[row][mid]=to_string(root->val);
        dfs(root->left,ans,row+1,l,mid-1);
        dfs(root->right,ans,row+1,mid+1,r);

    }
    vector<vector<string>> printTree(TreeNode* root) {
        int row=height(root);
        int col=(1<<row)-1;
        vector<vector<string>>ans;
        for(int i=0;i<row;i++){
            vector<string>s;
            for(int j=0;j<col;j++){
                s.push_back("");
            }ans.push_back(s);
        }
        dfs(root,ans,0,0,col-1);
        return ans;
    }
};