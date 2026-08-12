class Solution {
public:
    long long calc(int i,vector<int>&p,vector<pair<int,long long>>&h,int& max_h){
        if(i==0)return 1;
        if(h[i].second!=0)return h[i].second;
        long long curr_h=calc(p[i],p,h,max_h)+1;
        h[i]={i,curr_h};
        max_h=max(max_h,(int)curr_h);
        return max_h;
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        long long sum=0;
        int n=parent.size();
        vector<pair<int,long long>>h(n,{0,0});
        h[0]={0,1};
        int max_h=1;
        for(int i=1;i<n;i++){
            calc(i,parent,h,max_h);
        }
        for(int i=0;i<n;i++){
            sum+=(long long)nums[i]*(max_h-h[i].second+1);
        }
        return sum;
    }
};