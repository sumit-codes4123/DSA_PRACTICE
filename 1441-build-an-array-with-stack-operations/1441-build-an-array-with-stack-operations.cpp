class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int l=target.size(),k=1,i=0;
        vector<string>st;
        while(i<l){
            if(target[i]==k){
                st.push_back("Push");
                i++;
            }else{
                st.push_back("Push");
                st.push_back("Pop");
            }k++;
        }return st;
    }
};