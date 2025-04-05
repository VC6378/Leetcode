class Solution {
public:

    int f(vector<int> &nums,int ind,int xr){
        if(ind==nums.size()) return xr;
        int take = f(nums,ind+1,xr^nums[ind]);
        int nottake = f(nums,ind+1,xr);
        return take+nottake;
    }

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return f(nums,0,0);
    }
};