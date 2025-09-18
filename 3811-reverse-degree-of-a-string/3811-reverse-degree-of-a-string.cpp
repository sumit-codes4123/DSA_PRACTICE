class Solution {
public:
    int reverseDegree(string s) {
      long long sum=0;
       for(int i=0;i<s.size();i++){
        int n=26 - (s[i] - 'a');
        sum+=n*(i+1);  
       } return (int)sum;
    }
};