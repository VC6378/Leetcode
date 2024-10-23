class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        sort(nums.begin(),nums.end());
        int hehe = 1;
        int lstind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j] > dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
                if(hehe<dp[i]){
                    hehe=dp[i];
                    lstind=i;
                }
            }
        }

        vector<int> ans;
        ans.push_back(nums[lstind]);
        while(hash[lstind]!=lstind){
            lstind=hash[lstind];
            ans.push_back(nums[lstind]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};