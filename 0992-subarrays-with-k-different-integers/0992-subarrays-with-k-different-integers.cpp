class Solution {
public:
    
    int atmst(vector<int> &nums,int k){
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int unique=0;
        int ans=0;
        while(j<n){
            if(mp.find(nums[j])==mp.end()){
                unique++;
            }
            mp[nums[j]]++;
            while(unique>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    unique--;
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
            ans+=(j-i+1);
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int first=atmst(nums,k);
        int second=atmst(nums,k-1);
        return first-second;
    }
};