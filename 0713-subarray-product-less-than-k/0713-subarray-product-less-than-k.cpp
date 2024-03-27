class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0,end=0;
        int prod=1;
        int ans=0;
        int n=nums.size();
        while(end<n){
            prod*=nums[end++];
            while(start<end && prod>=k){
                prod /= nums[start++];
            }
            ans+=(end-start);
        }
        return ans;
    }
};