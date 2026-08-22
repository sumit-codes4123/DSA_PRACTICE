class Solution {
public:
    vector<int>ans;
    pair<bool,int>make_tr(TreeNode* root){
        if(root==NULL)return {true,0};
        pair<bool,int>l=make_tr(root->left);
        pair<bool,int>r=make_tr(root->right);
        if(l.first&&r.first&&l.second==r.second){
            int s=l.second+r.second+1;
            ans.push_back(s);
            return {true,s};
        }
        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(root==NULL)return -1;
        ans.clear();
        make_tr(root);
        sort(ans.begin(),ans.end(),greater<int>());
        if(ans.size()>=k)return ans[k-1];
        return -1;
    }
};