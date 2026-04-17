/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void buildString(TreeNode * root,string &s){
        if(root==NULL){
            s+="#,";
            return ;
        }
        s+=to_string(root->val)+",";
        buildString(root->left,s);
        buildString(root->right,s);

    }
    string serialize(TreeNode* root) {
        string s="";
        buildString(root,s);
        return s;
    }
    TreeNode* BuildTree(vector<string>&nodes,int &i){
        if(nodes[i]=="#"){
            i++;
            return NULL;
        }
        TreeNode *root=new TreeNode(stoi(nodes[i])); 
        i++;
        root->left=BuildTree(nodes,i);
        root->right=BuildTree(nodes,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        string temp="";
        for(char c:data){
            if(c==','){
                nodes.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        int i=0;
        return BuildTree(nodes,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;