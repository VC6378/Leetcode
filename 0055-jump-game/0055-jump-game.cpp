class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int ans;
        int maxjump=0;
        for(int i=0;i<n;i++){
            maxjump = max(maxjump,i+nums[i]);
            if(maxjump<i+1) break;
        }
        if(maxjump>=n-1) return true;
        return false;
    }
};