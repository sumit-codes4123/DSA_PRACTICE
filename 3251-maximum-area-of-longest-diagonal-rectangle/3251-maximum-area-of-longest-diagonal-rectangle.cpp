class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int maxdiag=0;
        int area=0;
      for(int i=0;i<n;i++){
        long long l=dimensions[i][0];
        long long w=dimensions[i][1];
          long long c=(l*l+w*w);
            if(maxdiag<c||(c==maxdiag &&l*w>area)){
                maxdiag=c;
                area=l*w;
            }
      }  return area;
    }
};