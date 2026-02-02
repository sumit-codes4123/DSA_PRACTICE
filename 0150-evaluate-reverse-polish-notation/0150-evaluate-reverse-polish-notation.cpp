class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                long long a=int(st.top());
                st.pop();
                long long b=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(b+a);
                if(tokens[i]=="-") st.push(b-a);
                if(tokens[i]=="*") st.push(b*a);
                if(tokens[i]=="/") st.push(b/a);
            }
            else st.push(stoll(tokens[i]));
        }return int(st.top());
    }
};