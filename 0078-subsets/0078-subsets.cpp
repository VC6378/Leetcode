class Solution {
public:

    void f(vector<int>&nums,vector<vector<int>> &ans,vector<int> &temp,int indx){
        int n=nums.size();
        if(indx>=n){
            ans.push_back(temp);
            return;
        }
        f(nums,ans,temp,indx+1);
        temp.push_back(nums[indx]);
        f(nums,ans,temp,indx+1);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums,ans,temp,0);
        return ans;
    }
};