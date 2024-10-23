class Solution {
public:
    vector<vector<int>> ans;

    void f(vector<int> &candidates,int target,vector<int> &temp,int ind){
        if(ind>=candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }

        if(candidates[ind]<=target){
            temp.push_back(candidates[ind]);
            f(candidates,target-candidates[ind],temp,ind);
            temp.pop_back();
        }
        f(candidates,target,temp,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        f(candidates,target,temp,0);
        return ans;
    }
};