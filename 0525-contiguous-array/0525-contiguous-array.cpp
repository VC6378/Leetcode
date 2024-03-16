class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) sum++;
            else sum--;
            if(sum==0){
                ans=max(ans,i+1);
            }
            else{
                if(mp.find(sum)!=mp.end()){
                    ans=max(ans,i-mp[sum]);
                }
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return ans;
    }
};