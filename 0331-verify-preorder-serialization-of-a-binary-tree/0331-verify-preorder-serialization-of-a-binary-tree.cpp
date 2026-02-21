class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return false;
        int c=1;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==',') continue;
            c--;
            if(c<0)return false;
            if(preorder[i]!='#'){
                if(i<preorder.size()&&preorder[i]!=',')
               i++;
                c+=2;
            }
        }if(c==0)return true;
        return false;
    }
};