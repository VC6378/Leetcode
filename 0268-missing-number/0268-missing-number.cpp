class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};