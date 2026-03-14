class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixgcd(n);
        int mx=-1;
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixgcd[i]=__gcd(mx,nums[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum=0;
        int left=0,right=n-1;
        while(left<right){
            sum+=__gcd(prefixgcd[left],prefixgcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};