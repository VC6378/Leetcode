class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0){
                curr=0;
            }
        }
        return maxi;
    }
};