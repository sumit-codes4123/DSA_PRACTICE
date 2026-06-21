class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int a=max(0,i-lights[i]);
                int b=min(n-1,i+lights[i]);
                vis[a]=max(vis[a],b);
            }
        }
        int i=0;
        int cnt=0;
        int crmr=-1;
        while(i<n){
            crmr=max(crmr,vis[i]);
            if(crmr>=i){
                i++;
            }else{
                cnt++;
                crmr=max(crmr,i+2);
                i++;
            }
        }
        return cnt;
    }
};