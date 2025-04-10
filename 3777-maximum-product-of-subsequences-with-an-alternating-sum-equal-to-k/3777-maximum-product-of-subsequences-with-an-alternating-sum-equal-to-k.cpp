class Solution {
public:

    int f(vector<int> &nums,int k,int limit,int ind,long long prod,int sum,int prev,int taken,unordered_map<string,int> &mp){
        int n = nums.size();
        if(ind>=n){
            if(taken && sum==k && prod<=limit) return prod;
            return -1;
        }

        string key = to_string(ind) + to_string(prod) + to_string(sum) + to_string(prev) + to_string(taken);
        if(mp.count(key)) return mp[key];
        int nottaken = f(nums,k,limit,ind+1,prod,sum,prev,taken,mp);
        int take = f(nums,k,limit,ind+1,(prod*nums[ind])>limit?limit+1:prod*nums[ind],prev?sum+nums[ind]:sum-nums[ind],!prev,1,mp);
        return mp[key] = max(take,nottaken);
    }

    int maxProduct(vector<int>& nums, int k, int limit) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<abs(k)) return -1;
        unordered_map<string,int> mp;
        int ans = f(nums,k,limit,0,1LL,0,1,0,mp);
        return ans;
    }
};