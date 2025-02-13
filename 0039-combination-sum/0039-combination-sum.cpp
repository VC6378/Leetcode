class Solution {
public:

    void f(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int> &temp,int ind){
        if(ind>=candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            f(candidates,target-candidates[ind],ans,temp,ind);
            temp.pop_back();
        }
        f(candidates,target,ans,temp,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates,target,ans,temp,0);
        return ans;
    }
};