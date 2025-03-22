class Solution {
public:
    vector<vector<int>> dp;

    bool f(vector<int> &temp,int ind,int target){
        if(target==0) return true;
        if(target<0) return false;
        if(ind>=temp.size()) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];

        return dp[ind][target] = f(temp,ind+1,target) || f(temp,ind+1,target-temp[ind]);
    }

    bool check(int k,vector<int> &nums,vector<vector<int>> &queries){
        int n=nums.size();
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<k;j++){
                if(queries[j][0]<=i && queries[j][1]>=i){
                    temp.push_back(queries[j][2]);
                }
            }
            dp.clear();
            dp.resize(temp.size(),vector<int>(1e4+10,-1));
            if(!f(temp,0,nums[i])) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        int left = 0;
        int right = q;

        int ans = INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(check(mid,nums,queries)){
                ans = mid;
                right = mid-1;
            }
            else{
                left=mid+1;
            }
        }

        if(ans<=q){
            return ans;
        }
        return -1;
    }
};