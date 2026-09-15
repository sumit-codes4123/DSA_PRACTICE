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
    unordered_set<TreeNode*>st;
    void bfs(TreeNode* root,TreeNode* p){
        if(root!=NULL){
            bfs(root->left,root);
            bfs(root->right,root);
            if(p==NULL&&!st.contains(root)||!st.contains(root->left)||!st.contains(root->right)){
                ans++;
                st.insert(root);
                st.insert(p);
                st.insert(root->left);
                st.insert(root->right);
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        ans=0;
        st.insert(NULL);
        bfs(root,NULL);
        return ans;
    }
};