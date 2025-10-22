class Solution {
public:
    bool isPrime(int num){
        if(num==1) return false;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int prime = 0;
        for(int i=0;i<n;i++){
            if(isPrime(nums[i][i])) prime = max(prime,nums[i][i]);
            if(isPrime(nums[i][n-i-1])) prime = max(prime,nums[i][n-i-1]);
        }
        return prime;
    }
};