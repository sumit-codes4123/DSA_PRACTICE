class Solution {
public:
    int compress(vector<char>& c) {
       int i=0,j=0;
       while(i<c.size()){
        int g=1;
        while(i+g<c.size()&&c[i+g]==c[i]){
            g++;
        }
        c[j++]=c[i];
        if(g>1){
            for(char x:to_string(g)){
                c[j++]=x;
            }            
        }i+=g;
       }return j; 
    }
};