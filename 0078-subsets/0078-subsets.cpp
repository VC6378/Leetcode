class Solution {
public:
    
    void f(vector<vector<int>> &ans,vector<int> temp,vector<int> &nums,int ind){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        f(ans,temp,nums,ind+1);
        temp.push_back(nums[ind]);
        f(ans,temp,nums,ind+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans,temp,nums,0);
        return ans;
    }
};