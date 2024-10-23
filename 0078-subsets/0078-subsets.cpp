class Solution {
public:

    void f(vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,int ind){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        f(nums,ans,temp,ind+1);
        temp.push_back(nums[ind]);
        f(nums,ans,temp,ind+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(nums,ans,temp,0);
        return ans;
    }
};