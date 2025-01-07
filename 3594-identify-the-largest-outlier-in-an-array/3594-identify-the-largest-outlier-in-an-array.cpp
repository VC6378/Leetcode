class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
            sum+=it;
        }

        for(auto it:nums){
            int currsum=sum-it;
            mp[it]--;
            if(mp[it]==0) mp.erase(it);
            if(currsum%2==0 && mp.find(currsum/2)!=mp.end() && it>ans){
                ans=it;
            }
            mp[it]++;
        }
        return ans;
    }
};