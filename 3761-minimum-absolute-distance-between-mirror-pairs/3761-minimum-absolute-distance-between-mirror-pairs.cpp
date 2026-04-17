class Solution {
public:
    long reverse(int x){
        long r=0;
        while(x>0){
            r=r*10+x%10;
            x/=10;
        }return (int)r;
    }
    int minMirrorPairDistance(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,int>pos;
    int ans=n+1;
    for(int i=0;i<n;i++){
        int x=nums[i];
        if(pos.count(x)){
            ans=min(ans,abs(pos[x]-i));
        }
        pos[reverse(x)]=i;
    }
    return ans==n+1?-1:ans;
    }
};