class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r= height.size() - 1;
        int lmax = height[l];
        int rmax = height[r];
        int water = 0;

        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lmax){
                    lmax=height[l];
                }
                else{
                    water+=abs(height[l]-lmax);
                }
                l++;
            }
            else{
                if(height[r]>=rmax){
                    rmax=height[r];
                }else{
                    water+=abs(height[r]-rmax);
                }
                r--;
            }
        }  return water;   
    }
};