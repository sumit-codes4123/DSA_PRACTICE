class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int a=-1;
        for(int i=s.size()-2;i>=0;i--){
            if(s[i]<s[i+1]) {
                a=i;
                break;
            }
        }
        if(a==-1)return -1;
        for(int i=s.size()-1;i>=a;i--){
            if(s[i]>s[a]){
                swap(s[i],s[a]);
                break;
            }
        }
        reverse(s.begin()+a+1,s.end());
        long long ans=stoll(s);
        return ans>INT_MAX?-1:ans;
    }
};