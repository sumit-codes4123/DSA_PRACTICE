class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a=nums[0],b=nums[1],c=nums[2];
        if(a==b && b==c)return "equilateral";
        else if(a!=b && b!=c && c!=a && a+b>c && b+c>a && a+c>b )return "scalene";
        else if((a==b||b==c||c==a)&&(a+b>c && b+c>a && a+c>b))return "isosceles";
        else return "none";
    }
};