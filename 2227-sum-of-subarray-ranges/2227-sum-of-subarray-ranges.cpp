class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int smin=INT_MAX;
            int smax=INT_MIN;
            for(int j=i;j<n;j++){
                smin=min(smin,nums[j]);
                smax=max(smax,nums[j]);
                ans+=(smax-smin);
            }
            
        }
        return ans;
    }
};