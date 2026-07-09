class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        int n=c.size();
        vector<int>rm(n,0);
        for(int i=0;i<n;i++){
            rm[i]=c[i]-r[i];
        }
        int cnt =0;
        sort(rm.begin(),rm.end());
        for(int i=0;i<n;i++){
            if(rm[i]==0)cnt++;
            else if(rm[i]<=ar){
                ar-=rm[i];
                cnt++;
            }
            else break;
        }
        return cnt;
    }
};