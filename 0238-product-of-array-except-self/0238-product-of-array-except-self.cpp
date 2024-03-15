class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int zero=0;
        for(int i=0;i<n;i++){
            prod=prod*nums[i];
            if(nums[i]==0) zero++;
        }
        vector<int> ans;
        if(prod==0){
            if(zero==1){
                long long p=1;
                for(int i=0;i<n;i++){
                    if(nums[i]!=0){
                        p=p*nums[i];
                    }
                }
                for(int i=0;i<n;i++){
                    if(nums[i]==0){
                        ans.push_back(p);
                    }
                    else{
                        ans.push_back(0);
                    }
                }
            }
            else{
                for(int i=0;i<n;i++){
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};