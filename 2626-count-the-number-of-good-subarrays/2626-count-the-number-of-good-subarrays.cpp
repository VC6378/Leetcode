class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        long long ans=0;
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n){
            while(j<n and cnt<k){
                mp[nums[j]]++;
                cnt+=mp[nums[j]]-1;
                j++;
            }
            if(cnt<k)break;
            ans+=(n-j+1);
            mp[nums[i]]--;
            cnt-=(mp[nums[i]]);
            i++;
        }
        return ans;
    }
};